from PyQt6.QtCore import Qt, QSize
from PyQt6.QtWidgets import (
   QDialog,
   QDialogButtonBox,
   QFormLayout,
   QLineEdit,
   QLabel,
   QVBoxLayout,
   QMainWindow,
   QMessageBox,
   QWidget,
)

import random #удалить!!!


def db_is_empty():
   #fucntion c++
   flag = random.choice([0, 1])
   print(flag)
   return flag

def recieve_data_of_student(id):
   #info = function_recieved(id)
   #return info
   return ['Румянцев', 'Артем', 'Сергеевич', 'st077230']

def recieve_data_of_teacher(id):
   #info = function_recieved(id)
   #return info
   return ['Иванов', 'Иван', 'Иванович', 'id555666']

def recieve_data_of_lab(id):
   #info = function_recieved(id)
   #return info
   return ['Распределение Гаусса', 'id123456']

def remove_student_id(id):
   #function remove_student in C
   False
   print("Removing student")

def remove_teacher_id(id):
   #function remove_teacher in C
   False
   print("Removing teacher")

def remove_lab_id(id):
   #function remove_lab in C
   False
   print("Removing lab")
class PrintInfoStudent(QDialog):
   def __init__(self):
      super().__init__()

      self.setWindowTitle("Информация о студенте")
      self.setFixedSize(QSize(300, 150))

   def recieve_id(self, id, remove_flag):
      self.remove_flag = remove_flag
      self.id = id
      
      info = recieve_data_of_student(self.id)

      dialogLayout = QVBoxLayout()
      formLayout = QFormLayout()

      formLayout.addRow("Фамилия: ", QLabel(info[0]))
      formLayout.addRow("Имя: ", QLabel(info[1]))
      formLayout.addRow("Отчество: ", QLabel(info[2]))
      formLayout.addRow("id: ", QLabel(info[3]))
      dialogLayout.addLayout(formLayout)

      buttons = QDialogButtonBox()
      buttons.setStandardButtons(
         QDialogButtonBox.StandardButton.Cancel
         | QDialogButtonBox.StandardButton.Ok
      )
      buttons.accepted.connect(self.accept)
      buttons.accepted.connect(self.remove_student)
      buttons.rejected.connect(self.reject)

      dialogLayout.addWidget(buttons)
      self.setLayout(dialogLayout)

   def remove_student(self):
      if self.remove_flag:
         remove_student_id(self.id)


class PrintInfoTeacher(QDialog):
   def __init__(self):
      super().__init__()

      self.setWindowTitle("Информация о преподавателе")
      self.setFixedSize(QSize(300, 150))

   def recieve_id(self, id, remove_flag):
      self.remove_flag = remove_flag
      self.id = id
      
      info = recieve_data_of_teacher(self.id)

      dialogLayout = QVBoxLayout()
      formLayout = QFormLayout()

      formLayout.addRow("Фамилия: ", QLabel(info[0]))
      formLayout.addRow("Имя: ", QLabel(info[1]))
      formLayout.addRow("Отчество: ", QLabel(info[2]))
      formLayout.addRow("id: ", QLabel(info[3]))
      dialogLayout.addLayout(formLayout)

      buttons = QDialogButtonBox()
      buttons.setStandardButtons(
         QDialogButtonBox.StandardButton.Cancel
         | QDialogButtonBox.StandardButton.Ok
      )
      buttons.accepted.connect(self.accept)
      buttons.accepted.connect(self.remove_teacher)
      buttons.rejected.connect(self.reject)

      dialogLayout.addWidget(buttons)
      self.setLayout(dialogLayout)

   def remove_teacher(self):
      if self.remove_flag:
         remove_teacher_id(self.id)


class PrintInfoLab(QDialog):
   def __init__(self):
      super().__init__()

      self.setWindowTitle("Информация о установке")
      self.setFixedSize(QSize(300, 150))

   def recieve_id(self, id, remove_flag):
      self.remove_flag = remove_flag
      self.id = id
      
      info = recieve_data_of_lab(self.id)

      dialogLayout = QVBoxLayout()
      formLayout = QFormLayout()

      formLayout.addRow("Название: ", QLabel(info[0]))
      formLayout.addRow("id: ", QLabel(info[1]))
      dialogLayout.addLayout(formLayout)

      buttons = QDialogButtonBox()
      buttons.setStandardButtons(
         QDialogButtonBox.StandardButton.Cancel
         | QDialogButtonBox.StandardButton.Ok
      )
      buttons.accepted.connect(self.accept)
      buttons.accepted.connect(self.remove_lab)
      buttons.rejected.connect(self.reject)

      dialogLayout.addWidget(buttons)
      self.setLayout(dialogLayout)

   def remove_lab(self):
      if self.remove_flag:
         remove_lab_id(self.id)



