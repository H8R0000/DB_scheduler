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

class Teacher(QDialog):
   def __init__(self):
      super().__init__()

      self.surname = ''
      self.name = ''
      self.patr = ''
      self.id = ''

      self.setWindowTitle("Добавление преподавателя")
      self.setFixedSize(QSize(300, 150))

      dialogLayout = QVBoxLayout()
      formLayout = QFormLayout()

      info_teacher = [QLineEdit(), QLineEdit(), QLineEdit(), QLineEdit()]

      formLayout.addRow("Фамилия:", info_teacher[0])
      formLayout.addRow("Имя:", info_teacher[1])
      formLayout.addRow("Отчество:", info_teacher[2])
      formLayout.addRow("id:", info_teacher[3])
      dialogLayout.addLayout(formLayout)

      info_teacher[0].textEdited.connect(self.recieve_surname)
      info_teacher[1].textEdited.connect(self.recieve_name)
      info_teacher[2].textEdited.connect(self.recieve_patr)
      info_teacher[3].textEdited.connect(self.recieve_id)


      buttons = QDialogButtonBox()
      buttons.setStandardButtons(
         QDialogButtonBox.StandardButton.Cancel
         | QDialogButtonBox.StandardButton.Ok
      )
      buttons.accepted.connect(self.push_teacher)
      buttons.accepted.connect(self.accept)
      buttons.rejected.connect(self.reject)

      dialogLayout.addWidget(buttons)
      self.setLayout(dialogLayout)

   def recieve_surname(self, s):
      self.surname = s
   def recieve_name(self, s):
      self.name = s
   def recieve_patr(self, s):
      self.patr = s
   def recieve_id(self, s):
      self.id = s

   def push_teacher(self):
      #push strudent
      info_teacher = [self.surname, self.name, self.patr, self.id]
      
      count = 0
      for info in info_teacher:
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


      print(info_teacher)

