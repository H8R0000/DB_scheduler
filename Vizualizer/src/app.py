import sys
from PyQt6.QtWidgets import QApplication
import Main.MainWindow as mw


app = QApplication([])
window = mw.MainWindow()
window.show()

sys.exit(app.exec())