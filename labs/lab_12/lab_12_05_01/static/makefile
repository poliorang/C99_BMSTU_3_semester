CC := gcc
FLAGS := -std=c99 -Iinc -Wall -Werror -Wextra -Wpedantic -D STATIC

SRC := src/
UNIT := unit_tests/
OUT := out/

MKD := mkdir -p out
RM := rm -rf

FILES := $(filter-out $(SRC)main.c, $(wildcard $(SRC)*.c $(UNIT)*.c))

release : app.exe

debug : FLAGS += -g3 --coverage 
debug : app.exe

app.exe: libapp.a $(OUT)main.o
	$(CC) $(FLAGS) $(OUT)main.o -L. -lapp -o $@

unit_tests.exe: libapp.a 
	$(CC) $(FLAGS) -L. -lapp -o $@ -lcheck

$(OUT)%.o: $(SRC)%.c
	$(MKD) && $(CC) $(FLAGS) -c $< -o $(OUT)/$(addsuffix .o, $(basename $(notdir $<)))
	
$(OUT)%.o: $(UNIT)%.c
	$(MKD) && $(CC) $(FLAGS) -c $< -o $(OUT)/$(addsuffix .o, $(basename $(notdir $<)))

%.a : $(addprefix $(OUT), $(addsuffix .o,$(notdir $(basename $(FILES)))))
	ar rc $@ $^

include $(wildcard *.d)

.PHONY : clean debug release unit func

clean :
	$(RM) out *.a *.exe

func :
	make debug && bash make_func.sh

unit :
	make clean && make unit_tests.exe && ./unit_tests.exe
