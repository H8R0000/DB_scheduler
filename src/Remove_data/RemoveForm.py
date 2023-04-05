from PyQt6.QtCore import Qt, QSize
from PyQt6.QtWidgets import (
   QMainWindow,
   QPushButton,
   QVBoxLayout,
   QLabel,
   QLineEdit,
   QWidget
)

import Remove_data.RemoveFormStudent as RemoveFormStudent
import Remove_data.RemoveFormTeacher as RemoveFormTeacher
import Remove_data.RemoveFormLab as RemoveFormLab

class RemoveType(QMainWindow):
   def __init__(self):
      super().__init__()

      self.setWindowTitle("Работа с базой данных")
      self.setFixedSize(QSize(300, 150))
      
      self.student = RemoveFormStudent.Remove()
      self.teacher = RemoveFormTeacher.Remove()
      self.lab = RemoveFormLab.Remove()

      layout = QVBoxLayout()

      self.buttons = [QPushButton("Студент"), QPushButton("Преподаватель"), QPushButton("Лабораторная работа")]
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
