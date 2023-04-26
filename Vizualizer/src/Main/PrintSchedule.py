from PyQt6.QtCore import Qt, QSize
from PyQt6.QtWidgets import (
   QMainWindow,
   QPushButton,
   QVBoxLayout,
   QLabel,
   QLineEdit,
   QWidget,
   QDateEdit,
   QDialogButtonBox,
   QDialog
)
import os
import json 
import pandas as pd
import time



class Schedule(QDialog):
   def __init__(self):
      super().__init__()

      self.setWindowTitle("Расписание")
      self.setFixedSize(QSize(300, 150))

      layout = QVBoxLayout()
      text = QLabel("Выберете дату начала занятий")
      self.date = QDateEdit()
      layout.addWidget(text)
      layout.addWidget(self.date)
      widget = QWidget()
      widget.setLayout(layout)

      buttons = QDialogButtonBox()
      buttons.setStandardButtons(
         QDialogButtonBox.StandardButton.Cancel
         | QDialogButtonBox.StandardButton.Ok
      )
      buttons.accepted.connect(self.accept)
      buttons.accepted.connect(self.receive_date)
      buttons.accepted.connect(self.print_schedule)
      buttons.rejected.connect(self.reject)

      layout.addWidget(buttons)
      self.setLayout(layout)
      

   def receive_date(self):
      time = str(self.date.date().toPyDate())
      print(".\scheduler.exe -d " + time + " > schedule.json")
      os.system(".\scheduler.exe -d " + time + " > schedule.json")
   
   def print_schedule(self):

      while not os.path.exists("./schedule.json"):
         time.sleep(0.5)
      
      def align_center(x):
         return ['text-align: center' for x in x]

      writer = pd.ExcelWriter('../data/schedule.xlsx', engine='xlsxwriter')
      with open("./schedule.json", "rb") as f:
         file = json.load(f) 

      for i in range(len(file)):
         teacher = file[i]["teacher"]

         info_date_first = ["Время занятий: 9:25"]
         info_date_second = ["Время занятий: 13:25"]
         info_students_first_shift = []
         info_students_second_shift = []
         for index in range(len(file[i]["schedule"][0]["firstShift"])):
            info_students_first_shift.append(file[i]["schedule"][0]["firstShift"][index]["student"])
         for index in range(len(file[i]["schedule"][0]["secondShift"])):
            info_students_second_shift.append(file[i]["schedule"][0]["secondShift"][index]["student"])

         info_labs_first_shift = []
         info_labs_second_shift = []
         info_labs_first_shift_massive = [info_students_first_shift]
         info_labs_second_shift_massive = [info_students_second_shift]
         for info in file[i]["schedule"]:
            info_date_first.append(info["date"])
            info_date_second.append(info["date"])
            for index in range(len(info["firstShift"])):
               info_labs_first_shift.append(info["firstShift"][index]["laba"])
            for index in range(len(info["secondShift"])):
               info_labs_second_shift.append(info["secondShift"][index]["laba"])
            info_labs_first_shift_massive.append(info_labs_first_shift)
            info_labs_second_shift_massive.append(info_labs_second_shift)
      
            info_labs_first_shift = []
            info_labs_second_shift = []

         sched_first = dict(zip(info_date_first, info_labs_first_shift_massive))
         sched_second = dict(zip(info_date_second, info_labs_second_shift_massive))

         dt_first = pd.DataFrame(sched_first)
         dt_second = pd.DataFrame(sched_second)

         info_sheets = dict(zip([teacher], [dt_first]))
         for sheet_name in info_sheets.keys():
               info_sheets[sheet_name].style.apply(align_center, axis=0).to_excel(writer, sheet_name=sheet_name, index=False)
         info_sheets = dict(zip([teacher], [dt_second]))
         for sheet_name in info_sheets.keys():
               info_sheets[sheet_name].style.apply(align_center, axis=0).to_excel(writer, sheet_name=sheet_name, index=False, startrow= (len(info_students_first_shift)+2))
   
         for i in range(len(info_date_first)):
            writer.sheets[teacher].set_column(i, i, 30)

      writer.save()


