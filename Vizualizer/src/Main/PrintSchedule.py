from PyQt6.QtCore import Qt, QSize
from PyQt6.QtWidgets import (
   QMainWindow,
   QPushButton,
   QVBoxLayout,
   QLabel,
   QLineEdit,
   QWidget,
   QDateEdit,
   QDialogButtonBox,
   QDialog
)
import os

class Schedule(QDialog):
   def __init__(self):
      super().__init__()

      self.setWindowTitle("Расписание")
      self.setFixedSize(QSize(300, 150))

      layout = QVBoxLayout()
      text = QLabel("Выберете дату начала занятий")
      self.date = QDateEdit()
      layout.addWidget(text)
      layout.addWidget(self.date)
      widget = QWidget()
      widget.setLayout(layout)

      buttons = QDialogButtonBox()
      buttons.setStandardButtons(
         QDialogButtonBox.StandardButton.Cancel
         | QDialogButtonBox.StandardButton.Ok
      )
      buttons.accepted.connect(self.accept)
      buttons.accepted.connect(self.receive_date)
      buttons.rejected.connect(self.reject)

      layout.addWidget(buttons)
      self.setLayout(layout)
      

   def receive_date(self):
      time = str(self.date.date().toPyDate())
      os.system("../test/a.out " + time)