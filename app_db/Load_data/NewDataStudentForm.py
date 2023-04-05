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

import Load_data.StudentForm as StudentForm

class NewDataStudent(QMainWindow):
   def __init__(self):
      super().__init__()

      self.setWindowTitle("Добавление новых студентов")
      self.setFixedSize(QSize(300, 150))

      self.student = StudentForm.Student()

      layout = QVBoxLayout()

      push_student = QPushButton("Добавить только одного студента")
      data_students = QPushButton("Добавить студентов из файла")

      layout.addWidget(push_student)
      layout.addWidget(data_students)

      push_student.clicked.connect(self.add_student)
      data_students.clicked.connect(self.students_from_file)

      container = QWidget()
      container.setLayout(layout)
      self.setCentralWidget(container)

   def add_student(self):
      self.student.show()
      

   def students_from_file(self):
      path = QtWidgets.QFileDialog.getOpenFileName()[0]
      #student_from_file_c(path)
      self.hide()
