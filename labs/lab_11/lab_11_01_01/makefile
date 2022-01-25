CC := gcc
FLAGS := -std=c99 -Iinc -Wall -Werror -Wextra -Wpedantic

SRC := src/
UNIT := unit_tests/
OUT := out/

MKD := mkdir -p out
RM := rm -rf

CFILES := $(wildcard $(SRC)*.c)
FILTER := $(filter-out $(SRC)main.c, $(wildcard $(SRC)*.c $(UNIT)*.c))

release : app.exe

debug : FLAGS += -g3 --coverage 
debug : app.exe

app.exe:  $(addprefix $(OUT), $(addsuffix .o,$(notdir $(basename $(CFILES)))))
	$(CC) $(FLAGS) $^ -o app.exe

unit_tests.exe: $(addprefix $(OUT), $(addsuffix .o,$(notdir $(basename $(FILTER)))))
	$(CC) $(FLAGS) $^ -o unit_tests.exe -lcheck

$(OUT)%.o: $(SRC)%.c
	$(MKD) && $(CC) $(FLAGS) -c -MD $< -o $(OUT)/$(addsuffix .o, $(basename $(notdir $<)))
	
$(OUT)%.o: $(UNIT)%.c
	$(MKD) && $(CC) $(FLAGS) -c -MD $< -o $(OUT)/$(addsuffix .o, $(basename $(notdir $<)))

include $(wildcard *.d)

.PHONY : clean debug release unit

clean :
	$(RM) out *.exe

unit :
	make clean && make unit_tests.exe && ./unit_tests.exe
