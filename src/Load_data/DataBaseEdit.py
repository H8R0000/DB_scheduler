from PyQt6.QtCore import Qt, QSize
from PyQt6.QtWidgets import (
   QMainWindow,
   QPushButton,
   QVBoxLayout,
   QLabel,
   QLineEdit,
   QWidget
)

import Load_data.DataBaseEditType as DataBaseEditType
import Edit_data.EditForm as EditForm
import Remove_data.RemoveForm as RemoveForm

class BaseEdit(QMainWindow):
   def __init__(self):
      super().__init__()

      self.setWindowTitle("Работа с базой данных")
      self.setFixedSize(QSize(300, 150))
      
      self.new_data =DataBaseEditType.BaseType() 
      self.remove = RemoveForm.RemoveType()
      self.edit = EditForm.Edit()

      layout = QVBoxLayout()


      #Удалил изменение данных
      self.buttons = [QPushButton("Загрузить данные"), QPushButton("Удалить данные")]
      for button in self.buttons:
         button.setCheckable(True)

      layout.addWidget(self.buttons[0])
      self.buttons[0].clicked.connect(self.button_clicked_new_data)
      layout.addWidget(self.buttons[1])
      self.buttons[1].clicked.connect(self.button_clicked_remove)
      #layout.addWidget(self.buttons[2])
      #self.buttons[2].clicked.connect(self.button_clicked_edit)

      container = QWidget()
      container.setLayout(layout)
      self.setCentralWidget(container)

   def button_clicked_new_data(self):
      if (not self.edit.isVisible() and not self.remove.isVisible()):
         self.new_data.show()
   
   def button_clicked_edit(self):
      if (not self.new_data.isVisible() and not self.remove.isVisible()):
         self.edit.show()
   
   def button_clicked_remove(self):
      if (not self.new_data.isVisible() and not self.edit.isVisible()):
         self.remove.show()
