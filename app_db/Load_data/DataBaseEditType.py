from PyQt6.QtCore import Qt, QSize
from PyQt6.QtWidgets import (
   QMainWindow,
   QPushButton,
   QVBoxLayout,
   QLabel,
   QLineEdit,
   QWidget
)

import Load_data.NewDataStudentForm as NewDataStudentForm
import Load_data.NewDataTeacherForm as NewDataTeacherForm
import Load_data.NewDataLabForm as NewDataLabForm

class BaseType(QMainWindow):
   def __init__(self):
      super().__init__()

      self.setWindowTitle("Работа с базой данных")
      self.setFixedSize(QSize(300, 150))
      
      self.student = NewDataStudentForm.NewDataStudent()
      self.teacher = NewDataTeacherForm.NewDataTeacher() 
      self.lab = NewDataLabForm.NewDataLab()

      layout = QVBoxLayout()

      self.buttons = [QPushButton("Студент"), QPushButton("Преподаватель"), QPushButton("Установка")]
      for button in self.buttons:
         button.setCheckable(True)

      layout.addWidget(self.buttons[0])
      self.buttons[0].clicked.connect(self.button_clicked_student)
      layout.addWidget(self.buttons[1])
      self.buttons[1].clicked.connect(self.button_clicked_teacher)
      layout.addWidget(self.buttons[2])
      self.buttons[2].clicked.connect(self.button_clicked_lab)

      container = QWidget()
      container.setLayout(layout)
      self.setCentralWidget(container)

   def button_clicked_student(self):
      if (not self.lab.isVisible() and not self.teacher.isVisible()):
         self.student.show()
   
   def button_clicked_teacher(self):
      if (not self.student.isVisible() and not self.lab.isVisible()):
         self.teacher.show()
   
   def button_clicked_lab(self):
      if (not self.student.isVisible() and not self.teacher.isVisible()):
         self.lab.show()
