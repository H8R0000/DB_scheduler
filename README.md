# DB_scheduler
To start:
do: 
DB_scheduler/Vizualizer/src/app.py 

1. Установка vcpkg 

	cd d:\develop
	
	git clone https://github.com/microsoft/vcpkg
	
	.\vcpkg\bootstrap-vcpkg.bat
	
	Прописать путь в переменные окружения (PATH=d:\develop\vcpkg) 
	
	Выполнить с правами администратора:
	
	vcpkg integrate install
	
	Перезапустить visual studio
	
2. Установка зависимостей

	vcpkg install nlohmann-json:x64-windows
	
	vcpkg install cxxopts:x64-windows
	
