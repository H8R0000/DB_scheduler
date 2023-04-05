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

class Lab(QDialog):
   def __init__(self):
      super().__init__()

      self.name = ''
      self.id = ''

      self.setWindowTitle("Добавление установок")
      self.setFixedSize(QSize(300, 150))

      dialogLayout = QVBoxLayout()
      formLayout = QFormLayout()

      info_lab = [QLineEdit(), QLineEdit()]

      formLayout.addRow("Название:", info_lab[0])
      formLayout.addRow("id:", info_lab[1])
      dialogLayout.addLayout(formLayout)

      info_lab[0].textEdited.connect(self.recieve_name)
      info_lab[1].textEdited.connect(self.recieve_id)


      buttons = QDialogButtonBox()
      buttons.setStandardButtons(
         QDialogButtonBox.StandardButton.Cancel
         | QDialogButtonBox.StandardButton.Ok
      )
      buttons.accepted.connect(self.push_lab)
      buttons.accepted.connect(self.accept)
      buttons.rejected.connect(self.reject)

      dialogLayout.addWidget(buttons)
      self.setLayout(dialogLayout)

   def recieve_name(self, s):
      self.name = s
   def recieve_id(self, s):
      self.id = s

   def push_lab(self):
      #push strudent
      info_lab = [self.name, self.id]
      
      count = 0
      for info in info_lab:
         if info == '':
            if count != 2:
               dialog = QMessageBox(parent=self, text="Недопустимое пустое поле")
               dialog.setWindowTitle("Ошибка")
               dialog.exec()
               break
         count += 1
      
      if len(self.id) != 8:
         dialog = QMessageBox(parent=self, text="Недостаточное количество символов в поле id")
         dialog.setWindowTitle("Ошибка")
         dialog.exec()
         return


      print(info_lab)

