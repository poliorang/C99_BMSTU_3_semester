import sys
from functions import fill_fibonacci, filter_without_stock_memory, filter_with_stock_memory

funcs = ['fill_fibonacci', 'filter_without_stock_memory', 'filter_with_stock_memory']

if len(sys.argv) >= 5:
    func_name = sys.argv[3]
    if func_name in funcs:
        num = funcs.index(func_name)

    f_one = sys.argv[4]
    f_two = sys.argv[5]

    with open (f'{f_two}') as f2:
        elements = f2.readlines()

    if elements == []:
        print(0)
        exit(1)

    elements = elements[0]
    elements = elements.split(' ')
    elements = list(map(int, elements))
    if num == 0:
        with open(f'{f_one}') as f1:
            count = f1.readline()
        result = fill_fibonacci(int(count))
        for i in range(len(count)):
            if result[i] != elements[i]:
                print(1)
                break
        print(0)

    if num == 1:
        with open(f'{f_one}') as f1:
            count = f1.readlines()
        count = count[0]
        count = count.split(' ')
        count = list(map(int, count))

        result = filter_without_stock_memory(count)
        for i in range(len(elements)):
            if result[i] != elements[i]:
                print(1)
                break
        print(0)

    if num == 2:
        with open(f'{f_one}') as f1:
            count = f1.readlines()
        count = count[0]
        count = count.split(' ')
        count = list(map(int, count))

        result = filter_with_stock_memory(count)
        for i in range(len(elements)):
            if result[i] != elements[i]:
                print(1)
                break
        print(0)
