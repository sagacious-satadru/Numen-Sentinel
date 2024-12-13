// cpp/include/process_info.h
#pragma once
#include <string>
#include <cstdint>
#include <chrono>

class ProcessInfo
{
public:
    ProcessInfo(uint32_t pid, const std::string &name);

    // Core process information
    uint32_t getPid() const { return pid_; }
    const std::string &getName() const { return name_; }

    // Resource usage
    double getCpuUsage() const { return cpu_usage_; }
    size_t getMemoryUsage() const { return memory_usage_; }
    uint32_t getThreadCount() const { return thread_count_; }

    // Process state
    bool isResponding() const { return is_responding_; }
    const std::string &getPriority() const { return priority_; }

    // Update methods
    void updateCpuUsage(double usage);
    void updateMemoryUsage(size_t bytes);
    void updateThreadCount(uint32_t count);
    void updateResponding(bool responding);
    void updatePriority(const std::string &priority);

    // Time tracking
    std::chrono::system_clock::time_point getStartTime() const { return start_time_; }

private:
    uint32_t pid_;                                     // Process ID
    std::string name_;                                 // Process name
    double cpu_usage_ = 0.0;                           // CPU usage percentage
    size_t memory_usage_ = 0;                          // Memory usage in bytes
    uint32_t thread_count_ = 0;                        // Number of threads
    bool is_responding_ = true;                        // Is process responding
    std::string priority_;                             // Process priority level
    std::chrono::system_clock::time_point start_time_; // Process start time
};