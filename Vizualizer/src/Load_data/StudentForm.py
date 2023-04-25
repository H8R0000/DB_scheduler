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

class Student(QDialog):
   def __init__(self, remove):
      super().__init__()

      self.surname = ''
      self.name = ''
      self.patr = ''
      self.st = ''
      self.alive = ''
      self.id_group = ''
      self.spec = ''
      self.group_name = ''
      
      self.remove_new = remove

      self.setWindowTitle("Добавление студента")
      self.setFixedSize(QSize(300, 250))

      dialogLayout = QVBoxLayout()
      formLayout = QFormLayout()

      info_student = [QLineEdit(), QLineEdit(), QLineEdit(), QLineEdit(), QLineEdit(), QLineEdit(), QLineEdit()]

      formLayout.addRow("Фамилия:", info_student[0])
      formLayout.addRow("Имя:", info_student[1])
      formLayout.addRow("Отчество:", info_student[2])
      formLayout.addRow("id:", info_student[3])
      formLayout.addRow("Живой:", info_student[4])
      formLayout.addRow("Группа:", info_student[5])
      #formLayout.addRow("Лабораторная группа:", info_student[6])
      formLayout.addRow("Специализация:", info_student[6])
      dialogLayout.addLayout(formLayout)

      info_student[0].textEdited.connect(self.recieve_surname)
      info_student[1].textEdited.connect(self.recieve_name)
      info_student[2].textEdited.connect(self.recieve_patr)
      info_student[3].textEdited.connect(self.recieve_st)
      info_student[4].textEdited.connect(self.recieve_alive)
      info_student[5].textEdited.connect(self.recieve_group)
      #info_student[6].textEdited.connect(self.recieve_labg)
      info_student[6].textEdited.connect(self.recieve_spec)


      buttons = QDialogButtonBox()
      buttons.setStandardButtons(
         QDialogButtonBox.StandardButton.Cancel
         | QDialogButtonBox.StandardButton.Ok
      )
      buttons.accepted.connect(self.push_student)
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
   def recieve_st(self, s):
      self.st = s
   def recieve_alive(self, s):
      self.alive = s
   def recieve_group(self, s):
      self.group_name = s
   def recieve_labg(self, s):
      self.id_labg = s
   def recieve_spec(self, s):
      self.spec = s

   def push_student(self):
      #push strudent
      # group_to_id_group(self.id_group)
      info_student = [self.name, self.surname, self.patr, self.st, self.alive, self.spec, self.group_name]
      

      sess = mysqlx.get_session("mysqlx://root:Zxcqwe7931@127.0.0.1")
      schema = sess.get_schema("students_db")
      myTable = schema.get_table("student")
      
      count = 0
      for info in info_student:
         if info == '':
            if count != 2:
               dialog = QMessageBox(parent=self, text="Недопустимое пустое поле")
               dialog.setWindowTitle("Ошибка")
               dialog.exec()
               break
         count += 1
      
      if len(self.st) != 8:
         dialog = QMessageBox(parent=self, text="Недостаточное количество символов в поле id")
         dialog.setWindowTitle("Ошибка")
         dialog.exec()
         return

      myTable.insert("name", "surname", "patronymic", "st", "alive", "spec", "group_name").values(self.name, self.surname, self.patr, self.st, self.alive, self.spec, self.group_name).execute()

      self.remove_new.student.__init__()
      print(info_student)
   