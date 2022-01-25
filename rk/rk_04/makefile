CC := gcc
FLAG := -std=c99 -Wall -Werror -Wpedantic -Wextra
OBJS := list.o main.o 

build : app.exe

run : 
	make build && ./app.exe in.txt out.txt

clean :
	rm -rf *.o *.exe

app.exe : $(OBJS)
	$(CC) -o $@ $(OBJS)
	
list.o : list.c list.h
	$(CC) $(FLAG) -o $@ -c $<
	
main.o : main.c list.h errors_structures.h
	$(CC) $(FLAG) -o $@ -c $<
	
.PHONY : clean run build
