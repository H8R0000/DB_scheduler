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

import mysqlx

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

         sess = mysqlx.get_session("mysqlx://root:Zxcqwe7931@127.0.0.1")


         schema = sess.get_schema("students_db")
         myTable = schema.get_table("student")
         RowResult = myTable.select("id_st", "name", "surname", "patronymic", "st", "alive", "spec", "group_name").execute()
         students = RowResult.fetch_all()

         myTable = schema.get_table("teacher")
         RowResult = myTable.select("id_t", "name", "surname", "id_labg", "patr").execute()
         teachers = RowResult.fetch_all()
         
         myTable = schema.get_table("laba")
         RowResult = myTable.select("id_laba", "name", "labs_direction").execute()
         labs = RowResult.fetch_all()
         gf.print_data(students, teachers, labs)
   
   def button_clicked_schedule(self):
      if (not self.data_base_edit.isVisible() and not self.print_data.isVisible() and gf.db_is_empty()):
         self.schedule.show()


      

  