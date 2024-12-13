// cpp/src/process_manager.cpp
#include "process_manager.h"
#include <psapi.h>
#include <tlhelp32.h>
#include <stdexcept>

// Global variables for CPU usage calculation
namespace {
    ULARGE_INTEGER lastCPU, lastSysCPU, lastUserCPU;
    int numProcessors = 0;
    bool initialized = false;
}

ProcessManager::ProcessManager() {
    initializePerfCounters();
}

ProcessManager::~ProcessManager() {
    PdhCloseQuery(cpuQuery_);
}

void ProcessManager::initializePerfCounters() {
    if (PdhOpenQuery(nullptr, 0, &cpuQuery_) != ERROR_SUCCESS) {
        throw std::runtime_error("Failed to initialize PDH query");
    }
    
    // Initialize CPU tracking
    if (!initialized) {
        SYSTEM_INFO sysInfo;
        GetSystemInfo(&sysInfo);
        numProcessors = sysInfo.dwNumberOfProcessors;
        initialized = true;
    }
}

void ProcessManager::updateProcessList() {
    processes_.clear();

    // Create snapshot of current processes
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snapshot == INVALID_HANDLE_VALUE) {
        throw std::runtime_error("Failed to create process snapshot");
    }

    PROCESSENTRY32W processEntry = { sizeof(PROCESSENTRY32W) };

    // Iterate through all processes
    if (Process32FirstW(snapshot, &processEntry)) {
        do {
            HANDLE processHandle = OpenProcess(
                PROCESS_QUERY_INFORMATION | PROCESS_VM_READ,
                FALSE,
                processEntry.th32ProcessID
            );

            if (processHandle) {
                // Convert wide string to regular string
                std::wstring wideName(processEntry.szExeFile);
                std::string processName(wideName.begin(), wideName.end());

                // Create ProcessInfo object
                ProcessInfo info(processEntry.th32ProcessID, processName);

                // Update process metrics
                info.updateCpuUsage(calculateCPUUsage(processEntry.th32ProcessID));
                info.updateMemoryUsage(getProcessMemoryUsage(processHandle));
                info.updateThreadCount(getProcessThreadCount(processHandle));
                info.updateResponding(isProcessResponding(processHandle));
                info.updatePriority(getProcessPriority(processHandle));

                processes_.push_back(std::move(info));
                CloseHandle(processHandle);
            }
        } while (Process32NextW(snapshot, &processEntry));
    }

    CloseHandle(snapshot);
}

double ProcessManager::calculateCPUUsage(uint32_t pid) {
    HANDLE process = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, pid);
    if (process == NULL) return 0.0;

    static std::unordered_map<uint32_t, ULARGE_INTEGER> lastCPUTimes;
    static ULARGE_INTEGER lastSystemTime;

    FILETIME ftime, fsys, fuser;
    FILETIME sysIdle, sysKernel, sysUser;

    GetSystemTimeAsFileTime(&ftime);
    ULARGE_INTEGER now;
    memcpy(&now, &ftime, sizeof(FILETIME));

    if (GetProcessTimes(process, &ftime, &ftime, &fsys, &fuser)) {
        ULARGE_INTEGER sysTime, userTime;
        memcpy(&sysTime, &fsys, sizeof(FILETIME));
        memcpy(&userTime, &fuser, sizeof(FILETIME));

        ULARGE_INTEGER totalTime;
        totalTime.QuadPart = sysTime.QuadPart + userTime.QuadPart;

        double percent = 0.0;
        if (lastCPUTimes.find(pid) != lastCPUTimes.end()) {
            ULARGE_INTEGER lastTotal = lastCPUTimes[pid];
            ULONGLONG timeDiff = now.QuadPart - lastSystemTime.QuadPart;
            if (timeDiff > 0) {
                percent = ((totalTime.QuadPart - lastTotal.QuadPart) * 100.0) / timeDiff;
            }
        }

        lastCPUTimes[pid] = totalTime;
        lastSystemTime = now;

        CloseHandle(process);
        return percent;
    }

    CloseHandle(process);
    return 0.0;
}

// double ProcessManager::calculateCPUUsage(uint32_t pid) {
//     HANDLE process = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, pid);
//     if (process == NULL) return -1;

//     FILETIME ftime, fsys, fuser;
//     FILETIME createTime, exitTime, kernelTime, userTime;
//     GetSystemTimeAsFileTime(&ftime);

//     ULARGE_INTEGER now, sys, user;
//     memcpy(&now, &ftime, sizeof(FILETIME));

//     if (GetProcessTimes(process, &createTime, &exitTime, &kernelTime, &userTime)) {
//         memcpy(&sys, &kernelTime, sizeof(FILETIME));
//         memcpy(&user, &userTime, sizeof(FILETIME));

//         double percent = (sys.QuadPart - lastSysCPU.QuadPart) +
//                         (user.QuadPart - lastUserCPU.QuadPart);
//         percent /= (now.QuadPart - lastCPU.QuadPart);
//         percent /= numProcessors;
//         percent *= 100;

//         lastCPU = now;
//         lastUserCPU = user;
//         lastSysCPU = sys;

//         CloseHandle(process);
//         return percent < 0 ? 0 : percent;
//     }

//     CloseHandle(process);
//     return -1;
// }

size_t ProcessManager::getProcessMemoryUsage(HANDLE process) {
    PROCESS_MEMORY_COUNTERS_EX pmc;
    if (GetProcessMemoryInfo(process, (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc))) {
        return pmc.WorkingSetSize;
    }
    return 0;
}

uint32_t ProcessManager::getProcessThreadCount(HANDLE process) {
    DWORD processId = GetProcessId(process);
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
    if (snapshot == INVALID_HANDLE_VALUE) return 0;

    uint32_t threadCount = 0;
    THREADENTRY32 threadEntry = { sizeof(THREADENTRY32) };

    if (Thread32First(snapshot, &threadEntry)) {
        do {
            if (threadEntry.th32OwnerProcessID == processId) {
                threadCount++;
            }
        } while (Thread32Next(snapshot, &threadEntry));
    }

    CloseHandle(snapshot);
    return threadCount;
}

bool ProcessManager::isProcessResponding(HANDLE process) {
    return WaitForInputIdle(process, 1000) != WAIT_TIMEOUT;
}

std::string ProcessManager::getProcessPriority(HANDLE process) {
    int priority = GetPriorityClass(process);
    switch (priority) {
        case IDLE_PRIORITY_CLASS:         return "Idle";
        case BELOW_NORMAL_PRIORITY_CLASS: return "Below Normal";
        case NORMAL_PRIORITY_CLASS:       return "Normal";
        case ABOVE_NORMAL_PRIORITY_CLASS: return "Above Normal";
        case HIGH_PRIORITY_CLASS:         return "High";
        case REALTIME_PRIORITY_CLASS:     return "Realtime";
        default:                          return "Unknown";
    }
}

bool ProcessManager::terminateProcess(uint32_t pid) {
    HANDLE process = OpenProcess(PROCESS_TERMINATE, FALSE, pid);
    if (!process) return false;
    
    bool result = TerminateProcess(process, 1) != 0;
    CloseHandle(process);
    return result;
}

bool ProcessManager::setPriority(uint32_t pid, int priority) {
    HANDLE process = OpenProcess(PROCESS_SET_INFORMATION, FALSE, pid);
    if (!process) return false;
    
    bool result = SetPriorityClass(process, priority) != 0;
    CloseHandle(process);
    return result;
}