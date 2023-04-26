#import os
import json 
import pandas as pd

#os.system("./a.out 12")

def align_center(x):
    return ['text-align: center' for x in x]

writer = pd.ExcelWriter('../data/schedule.xlsx', engine='xlsxwriter')
with open("file.json", "rb") as f:
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

