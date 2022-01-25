CC := gcc
FLAGS := -std=c99 -Iinc -Wall -Werror -Wextra -D ARR_EXPORTS

SRC := src/
UNIT := unit_tests/
OUT := out/

MKD := mkdir -p out
RM := rm -rf

FILES := $(filter-out $(SRC)main.c, $(wildcard $(SRC)*.c))
CHFILES := $(wildcard $(UNIT)*.c))

release : app.exe

debug : FLAGS += -g3 --coverage 
debug : app.exe

app.exe: libapp.dll $(OUT)main.o 
	$(CC) $(FLAGS) $(OUT)main.o -L. -lapp -o $@

unit_tests.exe: libapp.dll $(addprefix $(OUT), $(addsuffix .o, $(notdir $(basename $(CHFILES)))))
	$(CC) $(FLAGS) $(addprefix $(OUT), $(addsuffix .o, $(notdir $(basename $(CHFILES))))) -L. -lapp -o $@ -lcheck

$(OUT)%.o: $(SRC)%.c
	$(MKD) && $(CC) $(FLAGS) -c $< -o $(OUT)/$(addsuffix .o, $(basename $(notdir $<)))
	
$(OUT)%.o: $(UNIT)%.c
	$(MKD) && $(CC) $(FLAGS) -c $< -o $(OUT)/$(addsuffix .o, $(basename $(notdir $<)))

%.dll : $(addprefix $(OUT), $(addsuffix .o,$(notdir $(basename $(FILES)))))
	$(CC) -shared $^ -Wl,--subsystem,windows -o $@

include $(wildcard *.d)

.PHONY : clean debug release unit func

clean :
	$(RM) out *.dll *.exe

func :
	make release && bash make_func.sh

unit :
	make clean && make unit_tests.exe && ./unit_tests.exe
