#import os
#os.system("./a.out 12")


## импортируем библиотеку
#import json
## объявляем переменные
#string = "Some test string"
#integer = 211
#array = [1, 2, 3, 4, 5]
## создаем словарь
#mydict = {"title": string, "code": integer, "data": array}
## сериализуем его в JSON-структуру, как строку
#x = json.dumps(mydict)
## проводим десериализацию JSON-объекта
#y = json.loads(x)


import json # импортируем библиотеку

## создаем filehandler с помощью контекстного менеджера
#with open("data.json", "w") as fh:
    #json.dump([1, 2, 3, 4, 5], fh) # записываем структуру в файл


# открываем тот же файл, но уже на чтение
with open("schedule.json", "rb") as f:
   dict = json.load(f) # загружаем структуру из файла

count = len(dict[0]["schedule"])
info_students = []
for info_student in dict[0]["schedule"]:
   info_students.append(info_student)

print(info_students[0])