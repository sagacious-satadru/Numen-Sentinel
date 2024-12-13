// cpp/src/bindings.cpp
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "process_manager.h"

namespace py = pybind11;

PYBIND11_MODULE(process_monitor, m) {
    py::class_<ProcessInfo>(m, "ProcessInfo")
        .def_property_readonly("pid", &ProcessInfo::getPid)
        .def_property_readonly("name", &ProcessInfo::getName)
        .def_property_readonly("cpu_usage", &ProcessInfo::getCpuUsage)
        .def_property_readonly("memory_usage", &ProcessInfo::getMemoryUsage)
        .def_property_readonly("thread_count", &ProcessInfo::getThreadCount)
        .def_property_readonly("is_responding", &ProcessInfo::isResponding)
        .def_property_readonly("priority", &ProcessInfo::getPriority);

    py::class_<ProcessManager>(m, "ProcessManager")
        .def(py::init<>())
        .def("update_process_list", &ProcessManager::updateProcessList)
        .def("get_processes", &ProcessManager::getProcesses)
        .def("terminate_process", &ProcessManager::terminateProcess)
        .def("set_priority", &ProcessManager::setPriority);
}