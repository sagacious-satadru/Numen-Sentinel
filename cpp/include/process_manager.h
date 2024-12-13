// cpp/include/process_manager.h
#pragma once
#include "process_info.h"
#include <windows.h>
#include <pdh.h>
#include <vector>
#include <memory>
#include <unordered_map>

class ProcessManager {
public:
    ProcessManager();
    ~ProcessManager();

    // Prevent copying because of system resources
    ProcessManager(const ProcessManager&) = delete;
    ProcessManager& operator=(const ProcessManager&) = delete;

    // Core functionality
    void updateProcessList();
    std::vector<ProcessInfo>& getProcesses() { return processes_; }

    // Process operations
    bool terminateProcess(uint32_t pid);
    bool setPriority(uint32_t pid, int priority);

private:
    // Windows-specific handles and queries
    PDH_HQUERY cpuQuery_;
    std::unordered_map<uint32_t, PDH_HCOUNTER> cpuCounters_;
    
    // Process storage
    std::vector<ProcessInfo> processes_;

    // Helper methods
    void initializePerfCounters();
    double calculateCPUUsage(uint32_t pid);
    size_t getProcessMemoryUsage(HANDLE process);
    uint32_t getProcessThreadCount(HANDLE process);
    bool isProcessResponding(HANDLE process);
    std::string getProcessPriority(HANDLE process);
};