// cpp/src/process_info.cpp
#include "process_info.h"

ProcessInfo::ProcessInfo(uint32_t pid, const std::string& name)
    : pid_(pid)
    , name_(name)
    , start_time_(std::chrono::system_clock::now())
{
}

void ProcessInfo::updateCpuUsage(double usage) {
    cpu_usage_ = usage;
}

void ProcessInfo::updateMemoryUsage(size_t bytes) {
    memory_usage_ = bytes;
}

void ProcessInfo::updateThreadCount(uint32_t count) {
    thread_count_ = count;
}

void ProcessInfo::updateResponding(bool responding) {
    is_responding_ = responding;
}

void ProcessInfo::updatePriority(const std::string& priority) {
    priority_ = priority;
}