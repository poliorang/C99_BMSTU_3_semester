CC := gcc

CFLAGS := -std=c99 -Werror -Wall -Wpedantic -Wfloat-equal -Iinc
RM := rm -rf
I := inc/
O := out/
S := src/
OBJS := $(O)matrix.o $(O)add_delete.o $(O)allocate_in_out.o $(O)main.o 
OBJSCH := $(O)check_main.o $(O)matrix.o $(O)add_delete.o $(O)allocate_in_out.o $(O)check_matrix.o
TIME :=  $(O)allocate_in_out.o $(O)time_allocate.o 

release : app.exe

func : 
	make clean && make release && bash make_func.sh

unit :
	make clean && make unit_tests.exe && ./unit_tests.exe
	
out :
	mkdir out
	
time : 
	make time_allocate.exe && ./time_allocate.exe
	
	
	
time_allocate.exe : out $(TIME)
	$(CC) -o $@ $(TIME)
	
app.exe : out $(OBJS)
	$(CC) -o $@ $(OBJS)

unit_tests.exe : out $(OBJSCH)
	$(CC) -o $@ $(OBJSCH) -lcheck 
	
	
out/check_matrix.o : unit_tests/check_matrix.c
	$(CC) $(CFLAGS) -o $@ -c $<

out/check_main.o : unit_tests/check_main.c
	$(CC) $(CFLAGS) -o $@ -c $<
	



out/add_delete.o : $(S)add_delete.c $(I)add_delete.h
	$(CC) $(CFLAGS) -o $@ -c $<
	
out/matrix.o : $(S)matrix.c $(I)matrix.h
	$(CC) $(CFLAGS) -o $@ -c $<
		
out/allocate_in_out.o : $(S)allocate_in_out.c $(I)allocate_in_out.h
	$(CC) $(CFLAGS) -o $@ -c $<
	
out/main.o : $(S)main.c $(I)error.h $(I)matrix.h $(I)add_delete.h $(I)allocate_in_out.h
	$(CC) $(CFLAGS) -o $@ -c $<
	

out/time_allocate.o : $(S)time_allocate.c $(I)error.h $(I)allocate_in_out.h
	$(CC) $(CFLAGS) -o $@ -c $<


.PHONY : clean release func time


clean : 
	$(RM) *.exe
	$(RM) out
	

