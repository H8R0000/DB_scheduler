#!/usr/bin/python3
#-*- coding: utf-8 -*-

import ctypes 

# Загрузка библиотеки
testpp = ctypes.CDLL('./lib/libtest.so')


# Указываем, что функция возвращает указатель
testpp.test_new.restype = ctypes.c_void_p
# Создание класса test
test = testpp.test_new() 

##
# Работа с переменными
##

# Указываем, что функция возвращает int
testpp.test_get_a.restype = ctypes.c_int
# Указываем, что функция принимает аргумент void * 
testpp.test_get_a.argtypes = [ctypes.c_void_p]
# Указываем, что функция возвращает double
testpp.test_get_b.restype = ctypes.c_double
# Указываем, что функция принимает аргумент void * 
testpp.test_get_b.argtypes = [ctypes.c_void_p]
# Указываем, что функция возвращает char
testpp.test_get_c.restype = ctypes.c_char
# Указываем, что функция принимает аргумент void * 
testpp.test_get_c.argtypes = [ctypes.c_void_p]

print('\nРабота с переменными:')
print('ret test_get_a: ', testpp.test_get_a(test))
print('ret test_get_b: ', testpp.test_get_b(test))
print('ret test_get_c: ', testpp.test_get_c(test).decode("utf-8"))

# Указываем, что функция принимает аргумент void * 
testpp.test_del.argtypes = [ctypes.c_void_p]
# Удаляем класс
testpp.test_del(test) 