from PyQt6.QtCore import Qt, QSize
from PyQt6.QtWidgets import (
   QMainWindow,
   QPushButton,
   QVBoxLayout,
   QLabel,
   QLineEdit,
   QWidget
)

class Schedule(QMainWindow):
   def __init__(self):
      super().__init__()

      self.setWindowTitle("Расписание")
      self.setFixedSize(QSize(300, 150))
