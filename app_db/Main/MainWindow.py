from PyQt6.QtCore import Qt, QSize
from PyQt6.QtWidgets import (
   QMainWindow,
   QPushButton,
   QVBoxLayout,
   QLabel,
   QLineEdit,
   QWidget
)

import Used_func.GeneralFunction as gf

import Load_data.DataBaseEdit as DataBaseEdit 
import Main.PrintData as PrintData
import Main.PrintSchedule as PrintSchedule

class MainWindow(QMainWindow):
   def __init__(self):
      super().__init__()


      self.setWindowTitle("Главное меню")
      self.setFixedSize(QSize(300, 150))

      self.data_base_edit = DataBaseEdit.BaseEdit()
      self.print_data = PrintData.Data()
      self.schedule = PrintSchedule.Schedule()

      layout = QVBoxLayout()

      self.buttons = [QPushButton("База данных"), QPushButton("Выгрузка данных"), QPushButton("Составить расписание")]
      for button in self.buttons:
         button.setCheckable(True)

      layout.addWidget(self.buttons[0])
      self.buttons[0].clicked.connect(self.button_clicked_data_base_edit)
      layout.addWidget(self.buttons[1])
      self.buttons[1].clicked.connect(self.button_clicked_print_data)
      layout.addWidget(self.buttons[2])
      self.buttons[2].clicked.connect(self.button_clicked_schedule)

      container = QWidget()
      container.setLayout(layout)
      self.setCentralWidget(container)

   def button_clicked_data_base_edit(self):
      if (not self.print_data.isVisible() and not self.schedule.isVisible()):
         self.data_base_edit.show()
   
   def button_clicked_print_data(self):
      if (not self.data_base_edit.isVisible() and not self.schedule.isVisible() and gf.db_is_empty()):
         self.print_data.show()
   
   def button_clicked_schedule(self):
      if (not self.data_base_edit.isVisible() and not self.print_data.isVisible() and gf.db_is_empty()):
         self.schedule.show()


      