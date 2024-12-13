# test_bindings.py
import sys
import os
from pathlib import Path

# Get absolute path to build/Release directory
build_path = Path(__file__).parent / 'build' / 'Release'
print(f"Looking for module in: {build_path}")
sys.path.append(str(build_path))

try:
    print("Python path:", sys.path)
    print("Attempting to import process_monitor...")
    from process_monitor import ProcessManager
    print("Successfully imported process_monitor")
except ImportError as e:
    print(f"Import Error: {e}")
    print(f"Available files in {build_path}:")
    if build_path.exists():
        for file in build_path.glob('*'):
            print(f"  {file.name}")
    sys.exit(1)

def test_process_monitor():
    try:
        print("Creating ProcessManager instance...")
        pm = ProcessManager()
        
        print("Updating process list...")
        pm.update_process_list()
        
        print("Getting processes...")
        processes = pm.get_processes()
        
        print(f"\nFound {len(processes)} processes")
        
        print("\nDetails of first few processes:")
        for proc in processes[:5]:
            print(f"PID: {proc.pid}")
            print(f"Name: {proc.name}")
            print(f"CPU Usage: {proc.cpu_usage:.1f}%")
            print(f"Memory Usage: {proc.memory_usage / (1024*1024):.1f} MB")
            print(f"Thread Count: {proc.thread_count}")
            print(f"Priority: {proc.priority}")
            print(f"Responding: {proc.is_responding}")
            print("-" * 50)
            
    except Exception as e:
        print(f"Error during execution: {e}")
        import traceback
        traceback.print_exc()

if __name__ == "__main__":
    test_process_monitor()

# import sys
# import os

# # Add the build/Release directory to Python path
# build_path = os.path.join(os.path.dirname(__file__), 'build', 'Release')
# if not os.path.exists(build_path):
#     print(f"Build path does not exist: {build_path}")
#     sys.exit(1)
# sys.path.append(build_path)

# # Import our C++ module
# try:
#     from process_monitor import ProcessManager
# except ImportError as e:
#     print(f"Failed to import process_monitor module: {e}")
#     sys.exit(1)

# def test_process_monitor():
#     try:
#         # Create process manager instance
#         pm = ProcessManager()
        
#         # Update process list
#         pm.update_process_list()
        
#         # Get all processes
#         processes = pm.get_processes()
        
#         print(f"Found {len(processes)} processes")
        
#         # Print details of first few processes
#         for proc in processes[:5]:
#             print(f"PID: {proc.pid}")
#             print(f"Name: {proc.name}")
#             print(f"CPU Usage: {proc.cpu_usage:.1f}%")
#             print(f"Memory Usage: {proc.memory_usage / (1024*1024):.1f} MB")
#             print(f"Thread Count: {proc.thread_count}")
#             print(f"Priority: {proc.priority}")
#             print(f"Responding: {proc.is_responding}")
#             print("-" * 50)
            
#     except AttributeError as e:
#         print(f"Attribute error: {e}")
#     except Exception as e:
#         print(f"An error occurred: {e}")

# if __name__ == "__main__":
#     test_process_monitor()