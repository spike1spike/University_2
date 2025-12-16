from distutils.core import setup, Extension 

setup(
    name='minList',               # Имя пакета
    version='1.0',                 # Версия пакета
    ext_modules=[Extension('minList', ['Source.cpp'])]  # Указание расширения на C/C++, которое будет собрано из файла Source.cpp
)