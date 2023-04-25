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

      self.setWindowTitle("Удаление данных установок")
      self.setFixedSize(QSize(500, 350))

      self.remove_labs = gf.PrintInfoLab()

      sess = mysqlx.get_session("mysqlx://root:Zxcqwe7931@127.0.0.1")

      schema = sess.get_schema("students_db")
      myTable = schema.get_table("laba")
      RowResult = myTable.select("idlaba", "name", "direction").execute()
      self.labs = RowResult.fetch_all()

      #from random import choice
      #s =[['11', 'laba_n', 'labs_direct'], 
          #['11', 'laba_n', 'labs_direct123']]
      #self.labs = [choice(s)]
      
      name_labs = []
      self.id_labs = []
      block_labs = []

      for lab in self.labs:
         self.id_labs.append(lab[0])
         name_labs.append(lab[1])
         block_labs.append(lab[2])

      self.labs_db = pd.DataFrame({'Название': name_labs,
                        'Блок': block_labs})

      headers = ['Удаление', 'Название', 'Блок']

      rows = len(self.labs_db)
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
      buttons.accepted.connect(self.recieve_and_remove_lab)
      buttons.rejected.connect(self.reject)

      dialogLayout.addWidget(buttons)
      self.setLayout(dialogLayout)     

   def read_id(self, s):
      self.st = s

   def recieve_and_remove_lab(self):
      self.ButtonClicked()
      self.remove_labs.remove_flag = 1
      ### self.print_remove_lab.recieve_id(self.st, True)
      ### self.print_remove_lab.show()
      print(self.checked_list)
      print("Remove")
      for i in self.checked_list:
         self.remove_labs.id = self.id_labs[i]
         print(self.remove_labs.id)
         self.remove_labs.remove_lab()
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


       
      self.checked_list = []
   def ButtonClicked(self):
      for i in range(self.table.rowCount()):
         if self.table.cellWidget(i, 0).findChild(type(QCheckBox())).isChecked():
            self.checked_list.append(i)

   
   def edit_table(self):
      rows = len(self.labs_db)
      for row in range(rows):
         self.table.setItem(row, 1, QTableWidgetItem(str(self.labs_db['Название'][row])))
         self.table.setItem(row, 2, QTableWidgetItem(str(self.labs_db['Блок'][row])))
      delegate = ReadOnlyDelegate(self.table)
      self.table.setItemDelegateForColumn(1, delegate)
      self.table.setItemDelegateForColumn(2, delegate)




class ReadOnlyDelegate(QStyledItemDelegate):
   def createEditor(self, parent, option, index):
      return  