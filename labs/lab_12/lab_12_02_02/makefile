CC := gcc
FLAGS := -std=c99 -Ilib -Wall -Werror -Wextra -Wpedantic -D ARR_EXPORTS

LIB := lib/
UNIT := unit_tests/

RM := rm -rf

LIB_FILES := $(wildcard $(LIB)*.c)
CHFILES := $(wildcard $(UNIT)*.c))

relese : app.exe
	
debug : FLAGS += -g3 --coverage 
debug : app.exe
	
unit :
	make clean && make unit_tests.exe && ./unit_tests.exe

app.exe : libapp.dll $(LIB)main.o
	$(CC) $(FLAGS) $(LIB)main.o -L. -lapp -o $@

unit_tests.exe: libapp.dll $(addprefix $(UNIT), $(addsuffix .o, $(notdir $(basename $(CHFILES)))))
	$(CC) $(FLAGS) $(addprefix $(UNIT), $(addsuffix .o, $(notdir $(basename $(CHFILES))))) -L. -lapp -o $@ -lcheck

$(UNIT)%.o: $(UNIT)%.c
	$(CC) $(FLAGS) -c $< -o $(UNIT)/$(addsuffix .o, $(basename $(notdir $<)))
	
$(LIB)%.o: $(LIB)%.c
	$(CC) $(FLAGS) -c $< -o $(LIB)/$(addsuffix .o, $(basename $(notdir $<)))

%.dll : $(addprefix $(LIB), $(addsuffix .o, $(notdir $(basename $(LIB)array.c))))
	$(CC) -shared $^ -Wl,--subsystem,windows -o $@

include $(wildcard *.d)

.PHONY : clean debug release unit func

clean :
	$(RM) *.dll *.exe *.o 
	cd $(UNIT) && $(RM) *.dll *.exe *.o && cd ..
	cd $(LIB) && $(RM) *.dll *.exe *.o && cd ..

func :
	make clean && make app.exe && bash make_func.sh
