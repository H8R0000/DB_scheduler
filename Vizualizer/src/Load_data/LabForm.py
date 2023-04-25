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


import Remove_data.RemoveFormLab as rfl

class Lab(QDialog):
   def __init__(self, remove):
      super().__init__()

      self.name = ''
      self.block = ''

      self.remove_new = remove

      self.setWindowTitle("Добавление лабораторных работ")
      self.setFixedSize(QSize(300, 150))

      dialogLayout = QVBoxLayout()
      formLayout = QFormLayout()

      info_lab = [QLineEdit(), QLineEdit()]

      formLayout.addRow("Название:", info_lab[0])
      formLayout.addRow("Название блока:", info_lab[1])
      dialogLayout.addLayout(formLayout)

      info_lab[0].textEdited.connect(self.recieve_name)
      info_lab[1].textEdited.connect(self.recieve_block)


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
   def recieve_block(self, s):
      self.block = s

   def push_lab(self):
      #push strudent
      info_lab = [self.name, self.block]
      
      sess = mysqlx.get_session("mysqlx://root:Zxcqwe7931@127.0.0.1")
      schema = sess.get_schema("students_db")
      myTable = schema.get_table("laba")

      count = 0
      for info in info_lab:
         if info == '':
            if count == 0:
               dialog = QMessageBox(parent=self, text="Недопустимое пустое поле")
               dialog.setWindowTitle("Ошибка")
               dialog.exec()
               break
         count += 1
      
      myTable.insert("name", "direction").values(self.name, self.block).execute()

      self.remove_new.lab.__init__()


      print(info_lab)

