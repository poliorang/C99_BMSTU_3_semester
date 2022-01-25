CC := gcc
FLAG := -std=c99 -Wall -Werror -Wpedantic -Wextra
OBJS := matrix.o main.o 


build : app.exe

run : 
	make build && ./app.exe 

clean :
	rm -rf *.o *.exe

app.exe : $(OBJS)
	$(CC) -o $@ $(OBJS)
	
matrix.o : matrix.c matrix.h
	$(CC) $(FLAG) -o $@ -c $<
	
main.o : main.c matrix.h
	$(CC) $(FLAG) -o $@ -c $<
	
.PHONY : clean run build
	
