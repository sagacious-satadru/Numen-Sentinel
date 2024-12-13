# python/gui/main_window.py
import sys
import os
from PySide6.QtWidgets import QMainWindow, QWidget, QVBoxLayout
from PySide6.QtCore import Qt, QTimer
from .process_table import ProcessTableWidget

# Add the build/Release directory to Python path
build_path = os.path.join(os.path.dirname(os.path.dirname(os.path.dirname(__file__))), 'build', 'Release')
sys.path.append(build_path)

from process_monitor import ProcessManager

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Process Monitor")
        self.setMinimumSize(800, 600)

        # Initialize process manager
        self.process_manager = ProcessManager()
        
        # Create main widget and layout
        main_widget = QWidget()
        self.setCentralWidget(main_widget)
        layout = QVBoxLayout(main_widget)

        # Create process table
        self.process_table = ProcessTableWidget()
        layout.addWidget(self.process_table)

        # Update timer
        self.timer = QTimer()
        self.timer.timeout.connect(self.update_process_list)
        self.timer.start(1000)  # Update every second

    def update_process_list(self):
        try:
            self.process_manager.update_process_list()
            processes = self.process_manager.get_processes()
            self.process_table.update_process_data(processes)
        except Exception as e:
            print(f"Error updating process list: {e}")