from PyQt6.QtCore import Qt, QSize
from PyQt6 import QtWidgets
from PyQt6.QtWidgets import (
   QMainWindow,
   QCheckBox,
   QPushButton,
   QFormLayout,
   QVBoxLayout,
   QLabel,
   QLineEdit,
   QWidget
)

import Load_data.TeacherForm as TeacherForm 

class NewDataTeacher(QMainWindow):
   def __init__(self, remove):
      super().__init__()

      self.setWindowTitle("Добавление новых преподавателей")
      self.setFixedSize(QSize(300, 150))

      self.teacher = TeacherForm.Teacher(remove) 

      layout = QVBoxLayout()

      push_teacher = QPushButton("Добавить только одного преподавателя")
      #data_teachers = QPushButton("Добавить преподавателей из файла")

      layout.addWidget(push_teacher)
      #layout.addWidget(data_teachers)

      push_teacher.clicked.connect(self.add_teacher)
      #data_teachers.clicked.connect(self.teachers_from_file)

      container = QWidget()
      container.setLayout(layout)
      self.setCentralWidget(container)

   def add_teacher(self):
      self.teacher.show()

   def teachers_from_file(self):
      path = QtWidgets.QFileDialog.getOpenFileName()[0]
      #student_from_file_c(path)
      self.hide()
