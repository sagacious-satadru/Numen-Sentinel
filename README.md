# Numen Sentinel 🛡️

![License](https://img.shields.io/badge/license-MIT-blue.svg)
![Python](https://img.shields.io/badge/python-3.11+-blue)
![C++](https://img.shields.io/badge/C++-17-blue)
![Platform](https://img.shields.io/badge/platform-Windows-lightgrey)

A high-performance, real-time process monitoring solution that bridges C++ efficiency with Python's elegant GUI capabilities. **Numen Sentinel** provides deep insights into system processes with minimal overhead.

## 📜 Etymology & Significance

The name **Numen Sentinel** carries deep historical and philosophical significance:

*"Numen"* (plural: *numina*) originates from Roman and Latin culture, where it represented a divine spirit or supreme being. In Roman religion and mythology, a numen was considered a spiritual force or divine will present in all things, governing and influencing both the natural world and human affairs.

Derived from the Latin noun *numen* (meaning "divine will, divine power, divinity"), it described the divine presence or emanation inhabiting particular locations, objects, or persons. The numen commanded reverence and respect as a source of power and authority.

Just as the ancient numina watched over and guided their domains, **Numen Sentinel** serves as a vigilant guardian of your system's processes, providing divine-like oversight of your computer's operations. This name reflects our application's role as a protective, all-seeing monitor of system resources and processes.

## 🌟 Features

- **Real-time Process Monitoring**: Track CPU usage, memory consumption, and thread counts.
- **Hybrid Architecture**: C++ backend for performance, Python frontend for usability.
- **Resource-Efficient**: Optimized data collection with minimal system impact.
- **Professional GUI**: Clean, responsive interface built with Qt/PySide6.
- **Windows API Integration**: Direct system interaction for accurate metrics.

## 🚀 Technical Overview

### Architecture

**Numen Sentinel** employs a hybrid architecture that leverages the strengths of both C++ and Python:

#### C++ Backend (Core Engine)

- Windows API integration for direct process data access.
- RAII principles for resource management.
- Smart pointer utilization for memory safety.
- Performance-optimized data structures.

#### Python Frontend

- PySide6 (Qt) for professional-grade GUI.
- Event-driven architecture for responsive updates.
- Thread-safe data handling.
- Modern Python practices and type hints.

### Key Components

1. **Process Manager (C++)**

   - Direct Windows API interaction.
   - Performance Data Helper (PDH) integration.
   - Thread-safe process information collection.
   - Optimized CPU and memory metrics calculation.

2. **GUI Layer (Python/PySide6)**

   - Real-time data visualization.
   - Sortable process tables.
   - Resource usage graphs.
   - Event-driven updates.

3. **Language Bridge**

   - pybind11 for seamless C++/Python integration.
   - Zero-copy data transfer where possible.
   - Exception handling across language boundaries.

## 🛠️ Technical Deep-Dive

### Process Monitoring Methodology

The application employs sophisticated techniques for accurate process monitoring:

```cpp
// Example of our optimized CPU calculation
double ProcessManager::calculateCPUUsage(uint32_t pid) {
    // Advanced CPU time calculation
    // Kernel/User time differentiation
    // Per-core normalization
}
```

# 🎓 Learning Outcomes
This project demonstrates expertise in:

- Systems programming
- Multi-language application architecture
- GUI development
- Performance optimization
- Windows API integration
- Modern C++ and Python practices

# 🤝 Contributing
Contributions are welcome! Please read our contributing guidelines and code of conduct.

# 📝 License
This project is licensed under the MIT License.

# 🌟 Acknowledgments
- Windows API Documentation
- Qt/PySide6 Community
- Modern C++ Community
- Python Software Foundation
- Built with 💻💝` by sagacious-satadru with a passion for system programming and performance optimization.

*"Like the ancient numina watching over their sacred domains, Numen Sentinel stands guard over your system's processes."*