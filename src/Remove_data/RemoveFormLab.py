from PyQt6.QtCore import Qt, QSize
from PyQt6.QtWidgets import (
   QDialog,
   QDialogButtonBox,
   QFormLayout,
   QLineEdit,
   QVBoxLayout,
   QMainWindow,
   QMessageBox,
   QWidget,
)

import Used_func.GeneralFunction as gf

class Remove(QDialog):
   def __init__(self):
      super().__init__()

      self.setWindowTitle("Удаление данных утсановки")
      self.setFixedSize(QSize(300, 150))
      
      self.print_remove_lab = gf.PrintInfoLab()
      self.st = ''
      
      dialogLayout = QVBoxLayout()
      formLayout = QFormLayout()

      id = QLineEdit()

      formLayout.addRow("id:", id)
      dialogLayout.addLayout(formLayout)

      id.textEdited.connect(self.read_id)

      buttons = QDialogButtonBox()
      buttons.setStandardButtons(
         QDialogButtonBox.StandardButton.Cancel
         | QDialogButtonBox.StandardButton.Ok
      )
      buttons.accepted.connect(self.accept)
      buttons.accepted.connect(self.recieve_and_remove_lab)
      buttons.rejected.connect(self.reject)

      dialogLayout.addWidget(buttons)
      self.setLayout(dialogLayout)     

   def read_id(self, s):
      self.st = s

   def recieve_and_remove_lab(self):
      self.print_remove_lab.recieve_id(self.st, True)
      self.print_remove_lab.show()
   