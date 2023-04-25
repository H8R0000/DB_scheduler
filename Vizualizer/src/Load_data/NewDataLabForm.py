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

import Load_data.LabForm as LabForm

class NewDataLab(QMainWindow):
   def __init__(self, remove):
      super().__init__()

      self.setWindowTitle("Добавление новых лабораторных работ")
      self.setFixedSize(QSize(300, 150))

      self.lab = LabForm.Lab(remove)

      layout = QVBoxLayout()

      push_lab = QPushButton("Добавить только одну лабораторную работу")
      #data_labs = QPushButton("Добавить лабораторные работы из файла")

      layout.addWidget(push_lab)
      #layout.addWidget(data_labs)

      push_lab.clicked.connect(self.add_lab)
      #data_labs.clicked.connect(self.labs_from_file)

      container = QWidget()
      container.setLayout(layout)
      self.setCentralWidget(container)

   def add_lab(self):
      self.lab.show()

   def labs_from_file(self):
      path = QtWidgets.QFileDialog.getOpenFileName()[0]
      #student_from_file_c(path)
      self.hide()
