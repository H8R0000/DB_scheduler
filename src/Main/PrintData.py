from PyQt6.QtCore import Qt, QSize
from PyQt6.QtWidgets import (
   QMainWindow,
   QPushButton,
   QVBoxLayout,
   QLabel,
   QLineEdit,
   QWidget
)

class Data(QMainWindow):
   def __init__(self):
      super().__init__()

      self.setWindowTitle("Выгрузка")
      self.setFixedSize(QSize(300, 150))

