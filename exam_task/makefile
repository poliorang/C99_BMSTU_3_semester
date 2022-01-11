CC := gcc
FLAGS := -Wall -Werror
OBJS := functions.o main.o

app.exe : functions.o main.o
	$(CC) -o app.exe functions.o main.o

functions.o : functions.c functions.h
	$(CC) $(FLAGS) -c functions.c

main.o : main.c functions.h
	$(CC) $(FLAGS) -c $<

clean : 
	rm *.o *.exe

.PHONY : clean
