# Условие экзаменационной задачи 
_13.01.2022 - ИУ7-31Б_  
_(приведена не реальная задача, а подобная, фигурирующая годом ранее)_

Создавать мэйкфал не требуется, многофайловая организациия проекта не обязательна. 

`Условие задачи`

Пользователь вводит строки, длина которых не превосходит 80 символов. Строка со значением "The end" является последней (регистр важен). Очередная выделенная строка помещается в начала линейного односвязного списка. Узел списка хранит указатель на строку, память под строку выделяется динамически. Строка "The end" в список не помещается. После окончания ввод программа выводит строки в каждом узле на экран. Строки выводятся в одинарных кавычках через пробел (используется спецификатор "'%s' ").  
Приглашение к вводу выдавать не нужно.  
В конце работы программы вся динамически выделенная память должна быть освобождена.

`Пример`

_Ввод_  
Peter  
is  
name  
My  
The end  

_Вывод_  
'My' 'name' 'is' 'Peter'


_Ввод_  
The end

_Вывод_  
Empty list
