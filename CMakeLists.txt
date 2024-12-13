cmake_minimum_required(VERSION 3.15)
project(ProcessMonitor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Python
find_package(Python COMPONENTS Interpreter Development REQUIRED)

# Set explicit path for pybind11
set(pybind11_DIR "C:/Users/fcbsa/OneDrive/Documents/ProcessMonitorAppCppPython/ProcessMonitor/ProcessMonitorPythonVenv/Lib/site-packages/pybind11/share/cmake/pybind11")

# Find pybind11
find_package(pybind11 CONFIG REQUIRED)

# Add source files
set(SOURCES
    cpp/src/process_info.cpp
    cpp/src/process_manager.cpp
    cpp/src/bindings.cpp
)

# Create the Python module
pybind11_add_module(process_monitor ${SOURCES})

# Include directories
target_include_directories(process_monitor PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/cpp/include
)

# Windows-specific libraries
if(WIN32)
    target_link_libraries(process_monitor PRIVATE pdh psapi)
endif()

# cmake_minimum_required(VERSION 3.15)
# project(ProcessMonitor)

# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# # Add this block to help find pybind11
# execute_process(
#     COMMAND "${Python_EXECUTABLE}" -c "import pybind11; print(pybind11.get_cmake_dir())"
#     OUTPUT_VARIABLE pybind11_DIR
#     OUTPUT_STRIP_TRAILING_WHITESPACE
# )
# set(pybind11_DIR "${pybind11_DIR}")

# # Find Python and pybind11
# find_package(Python COMPONENTS Interpreter Development REQUIRED)
# find_package(pybind11 CONFIG REQUIRED)

# # Add source files
# set(SOURCES
#     cpp/src/process_info.cpp
#     cpp/src/process_manager.cpp
#     cpp/src/bindings.cpp
# )

# # Create the Python module
# pybind11_add_module(process_monitor ${SOURCES})

# # Include directories
# target_include_directories(process_monitor PRIVATE
#     ${CMAKE_CURRENT_SOURCE_DIR}/cpp/include
# )

# # Windows-specific libraries
# if(WIN32)
#     target_link_libraries(process_monitor PRIVATE pdh psapi)
# endif()


# cmake_minimum_required(VERSION 3.15)
# project(ProcessMonitor)

# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# # Find Python and pybind11
# find_package(Python COMPONENTS Interpreter Development REQUIRED)
# find_package(pybind11 CONFIG REQUIRED)

# # Add source files
# set(SOURCES
#     cpp/src/process_info.cpp
#     cpp/src/process_manager.cpp
#     cpp/src/bindings.cpp
# )

# # Create the Python module
# pybind11_add_module(process_monitor ${SOURCES})

# # Include directories
# target_include_directories(process_monitor PRIVATE
#     ${CMAKE_CURRENT_SOURCE_DIR}/cpp/include
# )

# # Windows-specific libraries
# if(WIN32)
#     target_link_libraries(process_monitor PRIVATE pdh psapi)
# endif()