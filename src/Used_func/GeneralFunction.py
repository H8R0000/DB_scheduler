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
import pandas as pd
import mysqlx

def db_is_empty():
   #fucntion c++
   flag = random.choice([0, 1])
   print(flag)
   return flag

def recieve_data_of_student(st):
   #info = function_recieved(id)
   #return info

   sess = mysqlx.get_session("mysqlx://root:Zxcqwe7931@127.0.0.1")
   schema = sess.get_schema("students_db")
   myTable = schema.get_table("student")


   student_info = myTable.select(['name', 'surname', 'patronymic', 'st']).where("id_st == " + str(st)).execute()
   
   return student_info.fetch_all()[0]

def recieve_data_of_teacher(id):
   #info = function_recieved(id)
   #return info

   sess = mysqlx.get_session("mysqlx://root:Zxcqwe7931@127.0.0.1")
   schema = sess.get_schema("students_db")
   myTable = schema.get_table("teacher")


   teacher_info = myTable.select(['name', 'surname', 'patr']).where("id_t == " + str(id)).execute()
   
   return teacher_info.fetch_all()[0]



def recieve_data_of_lab(id):
   #info = function_recieved(id)
   #return info
   
   sess = mysqlx.get_session("mysqlx://root:Zxcqwe7931@127.0.0.1")
   schema = sess.get_schema("students_db")
   myTable = schema.get_table("laba")


   laba_info = myTable.select(['name', 'labs_direction']).where("id_laba == " + str(id)).execute()
   
   return laba_info.fetch_all()[0]



def remove_student_id(id):
   sess = mysqlx.get_session("mysqlx://root:Zxcqwe7931@127.0.0.1")
   schema = sess.get_schema("students_db")
   myTable = schema.get_table("student")


   myTable.delete().where("id_st == " + str(id)).execute()

   print("Removing student")

def remove_teacher_id(id):
   sess = mysqlx.get_session("mysqlx://root:Zxcqwe7931@127.0.0.1")
   schema = sess.get_schema("students_db")
   myTable = schema.get_table("teacher")

   myTable.delete().where("id_t == " + str(id)).execute()
   print("Removing teacher")

def remove_lab_id(id):
   sess = mysqlx.get_session("mysqlx://root:Zxcqwe7931@127.0.0.1")
   schema = sess.get_schema("students_db")
   myTable = schema.get_table("laba")

   myTable.delete().where("id_laba == " + str(id)).execute()
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

      formLayout.addRow("Фамилия: ", QLabel(info[1]))
      formLayout.addRow("Имя: ", QLabel(info[0]))
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

      formLayout.addRow("Фамилия: ", QLabel(info[1]))
      formLayout.addRow("Имя: ", QLabel(info[0]))
      formLayout.addRow("Отчество: ", QLabel(info[2]))
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
      self.setFixedSize(QSize(300, 350))

   def recieve_id(self, id, remove_flag):
      self.remove_flag = remove_flag
      self.id = id
      
      info = recieve_data_of_lab(self.id)

      dialogLayout = QVBoxLayout()
      formLayout = QFormLayout()

      formLayout.addRow("Название: ", QLabel(info[0]))
      formLayout.addRow("Название блока: ", QLabel(info[1]))
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



def print_data(students, teachers, labs):

   name_students = []
   surname_students = []
   patr_students = []
   st_students = []
   alive_students = []
   spec_students = []
   group_students = []

   for student in students:
      name_students.append(student[1])
      surname_students.append(student[2])
      patr_students.append(student[3])
      st_students.append(student[4])
      alive_students.append(student[5])
      spec_students.append(student[6])
      group_students.append(student[7])

   students = pd.DataFrame({'Имя': name_students,
                      'Фамилия': surname_students,
                      'Отчество': patr_students,
                      'st': st_students,
                      'Живой': alive_students,
                      'Специализация': spec_students,
                      'Группы': group_students})



   name_teachers = []
   surname_teachers = []
   patr_teachers = []
   id_teachers = []
   group_teachers = []

   for teacher in teachers:
      name_teachers.append(teacher[1])
      surname_teachers.append(teacher[2])
      patr_teachers.append(teacher[4])
      group_teachers.append(teacher[3])
      id_teachers.append(teacher[0])

   teachers = pd.DataFrame({'Имя': name_teachers,
                      'Фамилия': surname_teachers,
                      'Отчество': patr_teachers,
                      'id_teacher': id_teachers,
                      "Лабораторная группа": group_teachers})



   name_labs = []
   id_labs = []
   block_labs = []

   for lab in labs:
      id_labs.append(lab[0])
      name_labs.append(lab[1])
      block_labs.append(lab[2])

   labs = pd.DataFrame({'Название': name_labs,
                      'id_labs': id_labs,
                      'Блок': block_labs})

#######################################################################################################

   info_sheets = {'Студенты': students, 'Преподаватели': teachers, 'Лабораторные работы': labs} # example with only students

   writer = pd.ExcelWriter('../data/all_data.xlsx', engine='xlsxwriter')

   for sheet_name in info_sheets.keys():
      info_sheets[sheet_name].to_excel(writer, sheet_name=sheet_name, index=False)

   writer.save()