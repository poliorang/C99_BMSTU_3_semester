import tkinter as tk
from functions import fill_fibonacci, filter_without_stock_memory, filter_with_stock_memory

''' функции вывода в ткинтере '''
def output_fibonacci(n):
    array = fill_fibonacci(n)

    line = ''
    for num in list(array):
        line += str(num) + ' '

    output_1.delete(0, tk.END)
    output_1.insert(0, line)


def output_filter_without_stock(line):
    nums = line.split(' ')
    nums = list(map(int, nums))
    array = filter_without_stock_memory(nums)

    line = ''
    for num in list(array):
        line += str(num) + ' '

    output_2_2.delete(0, tk.END)
    output_2_2.insert(0, line)


def output_filter_with_stock(line):
    nums = line.split(' ')
    nums = list(map(int, nums))

    array = filter_with_stock_memory(nums)

    line = ''
    for num in list(array):
        line += str(num) + ' '

    output_2_1.delete(0, tk.END)
    output_2_1.insert(0, line)

win = tk.Tk("lab 12")
win.geometry('500x500+700+300')

label_1 = tk.Label(text = "Fill the array with fibonacci numbers").place(x = 150, y = 24)
label_2 = tk.Label(text = "Enter the count of numbers").place(x = 165, y = 64)
label_3 = tk.Label(text = "Result").place(x = 220, y = 115)
input_1 = tk.Entry(win, justify = tk.RIGHT)
input_1.place(x = 170, y = 90)
output_1 = tk.Entry(win, justify = tk.RIGHT)
output_1.place(x = 170, y = 135)

label_4 = tk.Label(text = "Select only the first occurrences of numbers").place(x = 130, y = 198)
label_5 = tk.Label(text = "Enter the array").place(x = 195, y = 234)
input_2 = tk.Entry(win, justify = tk.RIGHT)
input_2.place(x = 170, y = 260)

label_6 = tk.Label(text = "First type of memory allocation (maximum size)").place(x = 120, y = 300)
output_2_1 = tk.Entry(win, justify = tk.RIGHT)
output_2_1.place(x = 170, y = 325)
label_7 = tk.Label(text = "Second type of memory allocation (with estimate)").place(x = 117, y = 360)
output_2_2 = tk.Entry(win, justify = tk.RIGHT)
output_2_2.place(x = 170, y = 385)

tk.Button(text = "fill", command = lambda : output_fibonacci(int(input_1.get()))).place(x = 300, y = 130)
tk.Button(text = "go", command = lambda : output_filter_with_stock(input_2.get())).place(x = 300, y = 325)
tk.Button(text = "go", command = lambda : output_filter_without_stock(input_2.get())).place(x = 300, y = 382)

win.mainloop()
