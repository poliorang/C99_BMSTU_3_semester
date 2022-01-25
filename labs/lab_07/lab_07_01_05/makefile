CC := gcc

CFLAGS := -std=c99 -Werror -Wall -Wpedantic -Wextra -Wvla -Wfloat-equal -Wconversion -Wvla
RM := rm -rf
COV := 
OBJS := out/functions.o out/key.o out/sort.o out/main.o 
OBJSCH := out/check_main.o out/sort.o out/check_sort.o out/key.o out/check_key.o out/check_functions.o out/functions.o 

release : app.exe

debug : COV = --coverage
debug : CFLAGS += -g3 $(COV)
debug : app.exe


app.exe : out $(OBJS)
	$(CC) $(COV) -o $@ $(OBJS)

unit_tests.exe : out $(OBJSCH)
	$(CC) -o $@ $(OBJSCH) -lcheck 
	
	
out/check_main.o : unit_tests/check_main.c
	$(CC) $(CFLAGS) -o $@ -c $<
	
out/check_key.o : unit_tests/check_key.c
	$(CC) $(CFLAGS) -o $@ -c $<
	
out/check_sort.o : unit_tests/check_sort.c
	$(CC) $(CFLAGS) -o $@ -c $<
	
out/check_functions.o : unit_tests/check_functions.c
	$(CC) $(CFLAGS) -o $@ -c $<

out :
	mkdir out


out/functions.o : src/functions.c inc/functions.h
	$(CC) $(CFLAGS) -o $@ -c $<

out/key.o : src/key.c inc/key.h
	$(CC) $(CFLAGS) -o $@ -c $<

out/sort.o : src/sort.c inc/sort.h
	$(CC) $(CFLAGS) -o $@ -c $<
	
out/main.o : src/main.c inc/key.h inc/functions.h
	$(CC) $(CFLAGS) -o $@ -c $<


.PHONY : clean debug release unit functions


clean :
	$(RM) *.o *.exe *.d *.gcno *.gcov *.gcda
	cd src && $(RM) *.o *.exe *.d *.gcno *.gcov *.gcda
	$(RM) out
	
func : 
	make debug && bash make_func.sh

unit :
	make clean && make unit_tests.exe && ./unit_tests.exe

