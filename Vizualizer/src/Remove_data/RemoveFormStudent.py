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

      self.setWindowTitle("Удаление данных студентов")
      self.setFixedSize(QSize(500, 350))
      
      self.remove_students = gf.PrintInfoStudent()

      sess = mysqlx.get_session("mysqlx://root:Zxcqwe7931@127.0.0.1")

      schema = sess.get_schema("students_db")
      myTable = schema.get_table("student")
      RowResult = myTable.select("id_st", "name", "surname", "patronymic", "st", "alive", "spec", "group_name").execute()
      self.students = RowResult.fetch_all()

      #from random import choice
      #s = [['2', 'Artem', 'Rum', 'Ser', 'st077230', '1', '123', '12'],
           #['2', 'Artem', 'Rum', 'Ser', 'st077230', '1', '123', '12as']]
      #self.students = [choice(s)]

      #print("Power on!!!")

      self.id_st = []
      name_students = []
      surname_students = []
      patr_students = []
      st_students = []
      alive_students = []
      spec_students = []
      group_students = []

      for student in self.students:
         self.id_st.append(student[0])
         name_students.append(student[1])
         surname_students.append(student[2])
         patr_students.append(student[3])
         st_students.append(student[4])
         alive_students.append(student[5])
         spec_students.append(student[6])
         group_students.append(student[7])

      self.students_db = pd.DataFrame({'Имя': name_students,
                        'Фамилия': surname_students,
                        'Отчество': patr_students,
                        'st': st_students,
                        'Живой': alive_students,
                        'Специализация': spec_students,
                        'Группа': group_students})
      headers = ['Удаление', 'Имя', 'Фамилия', 'Отчество', 'st', 'Живой', 'Специализация', 'Группа']
      

      rows = len(self.students_db)
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
      buttons.accepted.connect(self.recieve_and_remove_student)
      buttons.rejected.connect(self.reject)
      
      dialogLayout.addWidget(buttons)
      self.setLayout(dialogLayout)     



   def read_id(self, s):
      self.st = s

   def recieve_and_remove_student(self):
      self.ButtonClicked()
      ### self.print_remove_student.recieve_id(self.st, True) # выводит информацию об удаленном студенте (больше не нужно)
      ### self.print_remove_student.show()
      self.remove_students.remove_flag = 1
      print(self.checked_list)
      print("Remove")
      for i in self.checked_list:
         self.remove_students.id = self.id_st[i]
         print(self.remove_students.id)
         self.remove_students.remove_student()
      
      #self.sql_call()
      #self.edit_table()
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
      rows = len(self.students_db)
      for row in range(rows):
         self.table.setItem(row, 1, QTableWidgetItem(str(self.students_db['Имя'][row])))
         self.table.setItem(row, 2, QTableWidgetItem(str(self.students_db['Фамилия'][row])))
         self.table.setItem(row, 3, QTableWidgetItem(str(self.students_db['Отчество'][row])))
         self.table.setItem(row, 4, QTableWidgetItem(str(self.students_db['st'][row])))
         self.table.setItem(row, 5, QTableWidgetItem(str(self.students_db['Живой'][row])))
         self.table.setItem(row, 6, QTableWidgetItem(str(self.students_db['Специализация'][row])))
         self.table.setItem(row, 7, QTableWidgetItem(str(self.students_db['Группа'][row])))
      delegate = ReadOnlyDelegate(self.table)
      self.table.setItemDelegateForColumn(1, delegate)
      self.table.setItemDelegateForColumn(2, delegate)
      self.table.setItemDelegateForColumn(3, delegate)
      self.table.setItemDelegateForColumn(4, delegate)
      self.table.setItemDelegateForColumn(5, delegate)
      self.table.setItemDelegateForColumn(6, delegate)
      self.table.setItemDelegateForColumn(7, delegate)

      


class ReadOnlyDelegate(QStyledItemDelegate):
   def createEditor(self, parent, option, index):
      return