from PyQt6.QtCore import Qt, QSize
from PyQt6.QtGui     import *
from PyQt6.QtWidgets import *
from PyQt6.QtCore    import *
from PyQt6.QtWidgets import QStyledItemDelegate, QApplication, QTableWidget



import Used_func.GeneralFunction as gf
import mysqlx
import pandas as pd

class Remove(QDialog):
   def __init__(self):
      super().__init__()

      self.setWindowTitle("Удаление данных преподавателей")
      self.setFixedSize(QSize(500, 350))


      self.remove_teachers = gf.PrintInfoTeacher()
      
      sess = mysqlx.get_session("mysqlx://root:Zxcqwe7931@127.0.0.1")

      schema = sess.get_schema("students_db")
      myTable = schema.get_table("teacher")
      RowResult = myTable.select("id_t", "name", "surname", "patr").execute()
      self.teachers = RowResult.fetch_all()

      #from random import choice
      #s = [['12', 'Sef', 'Had', 'Grigi'],
           #['12', 'Sef', 'Had', 'Grigi12']]
      #self.teachers = [choice(s)]
         
      name_teachers = []
      surname_teachers = []
      patr_teachers = []
      self.id_teachers = []

      for teacher in self.teachers:
         self.id_teachers.append(teacher[0])
         name_teachers.append(teacher[1])
         surname_teachers.append(teacher[2])
         patr_teachers.append(teacher[3])

      self.teachers_db = pd.DataFrame({'Имя': name_teachers,
                        'Фамилия': surname_teachers,
                        'Отчество': patr_teachers})

      headers = ['Удаление', 'Имя', 'Фамилия', 'Отчество']

      rows = len(self.teachers_db) 
      columns = len(headers)
      self.checked_list = []

      self.table = QTableWidget(rows, columns, self)
      self.table.setHorizontalHeaderLabels(headers)
      for row in range(rows):
            widget   = QWidget()
            checkbox = QCheckBox()

            checkbox.setCheckState(Qt.CheckState.Unchecked)
            layoutH = QHBoxLayout(widget)
            layoutH.addWidget(checkbox)
            #layoutH.setContentsMargins(0, 0, 0, 0)

            self.table.setCellWidget(row, 0, widget)
            
      self.edit_table()

      dialogLayout = QVBoxLayout()
      dialogLayout.addWidget(self.table)


      buttons = QDialogButtonBox()
      buttons.setStandardButtons(
         QDialogButtonBox.StandardButton.Cancel
         | QDialogButtonBox.StandardButton.Ok
      )
      buttons.accepted.connect(self.accept)
      buttons.accepted.connect(self.recieve_and_remove_teacher)
      buttons.rejected.connect(self.reject)

      dialogLayout.addWidget(buttons)
      self.setLayout(dialogLayout)     

   def read_id(self, s):
      self.st = s

   def recieve_and_remove_teacher(self):
      self.ButtonClicked()
      self.remove_teachers.remove_flag = 1
      ### self.print_remove_teacher.recieve_id(self.st, True)
      ### self.print_remove_teacher.show()
      print(self.checked_list)
      print("Remove")
      for i in self.checked_list:
         self.remove_teachers.id = self.id_teachers[i]
         print(self.remove_teachers.id)
         self.remove_teachers.remove_teacher()
      for row in range(self.table.rowCount()):
         widget   = QWidget()
         checkbox = QCheckBox()

         checkbox.setCheckState(Qt.CheckState.Unchecked)
         layoutH = QHBoxLayout(widget)
         layoutH.addWidget(checkbox)
         #layoutH.setContentsMargins(0, 0, 0, 0)

         self.table.setCellWidget(row, 0, widget)
       
      self.checked_list = []
      self.__init__()



   def ButtonClicked(self):
      for i in range(self.table.rowCount()):
         if self.table.cellWidget(i, 0).findChild(type(QCheckBox())).isChecked():
            self.checked_list.append(i)

      
   
   def edit_table(self):
      rows = len(self.teachers_db) 
      for row in range(rows):
         self.table.setItem(row, 1, QTableWidgetItem(str(self.teachers_db['Имя'][row])))
         self.table.setItem(row, 2, QTableWidgetItem(str(self.teachers_db['Фамилия'][row])))
         self.table.setItem(row, 3, QTableWidgetItem(str(self.teachers_db['Отчество'][row])))
      delegate = ReadOnlyDelegate(self.table)
      self.table.setItemDelegateForColumn(1, delegate)
      self.table.setItemDelegateForColumn(2, delegate)
      self.table.setItemDelegateForColumn(3, delegate)


class ReadOnlyDelegate(QStyledItemDelegate):
   def createEditor(self, parent, option, index):
      return  