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
# Memory Management
Employs modern C++ practices:

- RAII for resource handling
- Smart pointers for memory safety
- Move semantics for efficient data transfer

## Performance Optimizations

   1. Snapshot Optimization
   
   - Efficient process enumeration
   - Minimal system API calls
   - Optimized data structures
   
   2. GUI Updates

   - Throttled refresh rates
   - Efficient data transfer
   - Minimal redraws
     
## 🎯 Best Practices
   - Modern C++ (17) Features
   
      - Smart pointers
      - RAII principles
      - Move semantics
      - Template metaprogramming
   
   - Python Best Practices
   
      - Type hints
      - Context managers
      - Generator expressions
      - Modern async patterns

## ⚗️ Code Quality

   - Comprehensive error handling
   - Thread safety
   - Memory leak prevention
   - Performance optimization

## 🔧 Technical Requirements
   - Windows 11/10
   - Python 3.11+
   - C++17 compatible compiler
   - CMake 3.15+
   - Qt/PySide6
## 🚀 Building from Source
```bash
# Clone repository
git clone https://github.com/sagacious-satadru/Numen-Sentinel.git
cd Numen-Sentinel

# Set up Python virtual environment
python -m venv ProcessMonitorPythonVenv
source ProcessMonitorPythonVenv/Scripts/activate  # Windows
pip install -r requirements.txt

# Build C++ components
mkdir build && cd build
cmake ..
cmake --build . --config Release

# Run application
python python/main.py
```

## 🎓 Learning Outcomes & Technical Expertise

This project demonstrates comprehensive expertise across multiple domains of software engineering. Each area represents critical skills valued in modern software development:

### 💻 Systems Programming
Our implementation dives deep into operating system internals, showcasing advanced systems programming concepts:
- Direct interaction with Windows process management systems
- Low-level memory management and resource handling
- System-level API integration for process metrics collection
- Thread management and synchronization techniques
- Understanding of process hierarchies and system resource allocation

The project exemplifies this through our `ProcessManager` class, which efficiently interfaces with the Windows kernel to gather detailed process information while maintaining system stability and security.

### 🔄 Multi-language Application Architecture
The project demonstrates sophisticated multi-language integration:
- Seamless bridging between C++ and Python using pybind11
- Efficient data transfer between languages with minimal overhead
- Language-specific optimizations (C++ for performance, Python for UI)
- Cross-language exception handling and resource management
- Architecture design that leverages each language's strengths

The hybrid approach in this project shows real-world expertise in designing systems that combine multiple programming paradigms while maintaining code quality and performance.

### 🎨 GUI Development
The application showcases modern GUI development practices:
- Implementation of responsive, user-friendly interfaces using Qt/PySide6
- Real-time data visualization and updates
- Event-driven programming patterns
- Thread-safe UI updates
- Custom widget development and styling
- Layout management and dynamic UI adjustments

The GUI implementation demonstrates understanding of both technical requirements and user experience considerations in modern application development.

### ⚡ Performance Optimization
The project implements various performance optimization techniques:
- Efficient process data collection with minimal system impact
- Memory-optimized data structures and algorithms
- Smart caching mechanisms for process information
- Throttled UI updates to balance responsiveness and resource usage
- Profile-guided optimization decisions

Our implementation shows practical application of performance optimization principles in a real-world scenario.

### 🔌 Windows API Integration
Deep integration with Windows systems demonstrates expertise in:
- Windows Process API utilization
- Performance Data Helper (PDH) implementation
- Security and access control management
- System resource monitoring
- Native API error handling and recovery

The project shows practical knowledge of Windows system programming and API integration in production-quality software.

### 📚 Modern C++ and Python Practices
Implementation follows current best practices in both languages:

**Modern C++:**
- RAII principle implementation for resource management
- Smart pointer usage for memory safety
- Move semantics for efficient object handling
- Template metaprogramming techniques
- Exception safety guarantees

**Modern Python:**
- Type hints and static type checking
- Context managers for resource handling
- Asyncio patterns for concurrent operations
- Modern package management and virtual environments
- Pythonic code design principles

### 🔍 Real-World Application
This project serves as a comprehensive demonstration of software engineering expertise by:
- Solving real-world system monitoring needs
- Implementing production-grade error handling
- Following industry-standard coding practices
- Maintaining code quality and documentation
- Considering security implications in system-level operations

Each of these areas represents crucial knowledge for modern software development, particularly in systems programming and application development roles. The project serves as a practical portfolio piece demonstrating the ability to create professional-grade software while handling complex technical challenges.

# 🤝 Contributing
Contributions are welcome! 

# 📝 License
This project is licensed under the MIT License.

# 🌟 Acknowledgments
- Windows API Documentation
- Qt/PySide6 Community
- Modern C++ Community
- Python Software Foundation
- Built with 💻💝` by sagacious-satadru with a passion for system programming and performance optimization.

*"Like the ancient numina watching over their sacred domains, Numen Sentinel stands guard over your system's processes."*
