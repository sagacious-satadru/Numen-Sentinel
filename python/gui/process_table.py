# python/gui/process_table.py
from PySide6.QtWidgets import QTableWidget, QTableWidgetItem
from PySide6.QtCore import Qt

class ProcessTableWidget(QTableWidget):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.setup_table()

    def setup_table(self):
        headers = ["PID", "Name", "CPU %", "Memory (MB)", 
                  "Threads", "Priority", "Status"]
        self.setColumnCount(len(headers))
        self.setHorizontalHeaderLabels(headers)
        
        # Enable sorting
        self.setSortingEnabled(True)
        
        # Set column widths
        self.setColumnWidth(0, 70)   # PID
        self.setColumnWidth(1, 200)  # Name
        self.setColumnWidth(2, 70)   # CPU
        self.setColumnWidth(3, 100)  # Memory
        self.setColumnWidth(4, 70)   # Threads
        self.setColumnWidth(5, 100)  # Priority
        self.setColumnWidth(6, 100)  # Status

    def update_process_data(self, processes):
        self.setSortingEnabled(False)
        self.setRowCount(len(processes))
        
        for row, process in enumerate(processes):
            self.setItem(row, 0, QTableWidgetItem(str(process.pid)))
            self.setItem(row, 1, QTableWidgetItem(process.name))
            self.setItem(row, 2, QTableWidgetItem(f"{process.cpu_usage:.1f}"))
            self.setItem(row, 3, QTableWidgetItem(f"{process.memory_usage / 1024 / 1024:.1f}"))
            self.setItem(row, 4, QTableWidgetItem(str(process.thread_count)))
            self.setItem(row, 5, QTableWidgetItem(process.priority))
            self.setItem(row, 6, QTableWidgetItem("Responding" if process.is_responding else "Not Responding"))

        self.setSortingEnabled(True)