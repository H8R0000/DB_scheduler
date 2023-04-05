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

import mysqlx

class Teacher(QDialog):
   def __init__(self):
      super().__init__()

      self.surname = ''
      self.name = ''
      self.patr = ''
      self.id_labg = ''

      self.setWindowTitle("Добавление преподавателя")
      self.setFixedSize(QSize(300, 150))

      dialogLayout = QVBoxLayout()
      formLayout = QFormLayout()

      info_teacher = [QLineEdit(), QLineEdit(), QLineEdit()]

      formLayout.addRow("Фамилия:", info_teacher[0])
      formLayout.addRow("Имя:", info_teacher[1])
      formLayout.addRow("Отчество:", info_teacher[2])
      #formLayout.addRow("Лабораторная группа:", info_teacher[3])
      dialogLayout.addLayout(formLayout)

      info_teacher[0].textEdited.connect(self.recieve_surname)
      info_teacher[1].textEdited.connect(self.recieve_name)
      info_teacher[2].textEdited.connect(self.recieve_patr)
      #info_teacher[3].textEdited.connect(self.recieve_labg)


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
   def recieve_labg(self, s):
      self.id_labg = s

   def push_teacher(self):
      #push strudent
      info_teacher = [self.name, self.surname, self.patr]
      

      sess = mysqlx.get_session("mysqlx://root:Zxcqwe7931@127.0.0.1")
      schema = sess.get_schema("students_db")
      myTable = schema.get_table("teacher")

      count = 0
      for info in info_teacher:
         if info == '':
            if count != 3:
               dialog = QMessageBox(parent=self, text="Недопустимое пустое поле")
               dialog.setWindowTitle("Ошибка")
               dialog.exec()
               break
         count += 1
      
      myTable.insert("name", "surname", "patr").values(self.name, self.surname, self.patr).execute()
      print(info_teacher)

