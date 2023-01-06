CC := gcc
 
SRCS_DIR := ./src
SRCS := $(wildcard $(SRCS_DIR)/*.c)
HDRS_DIR := ./inc
HDRS := $(wildcard $(HDRS_DIR)/*.h)
OBJS_DIR := ./out
$(shell mkdir -p $(OBJS_DIR))
OBJS := $(OBJS_DIR)/list_allocate.o $(OBJS_DIR)/list_operations.o $(OBJS_DIR)/read_list.o $(OBJS_DIR)/list_print.o
UNIT_DIR := ./unit_tests
UNIT_SRCS := $(wildcard $(UNIT_DIR)/*.h)
OBJS_TESTS_UNIT := $(OBJS_DIR)/check_main.o $(OBJS_DIR)/check_list_operations.o
 
CFLAGS := -I$(HDRS_DIR) -std=gnu99 -Wall -Werror -Wpedantic -Wextra
UFLAGS := $(shell pkg-config --cflags --libs check)
ULINKS := -lcheck -lrt -lpthread -lm
 
.PHONY = unit release debug coverage func clean object_dir
 
app.exe : $(OBJS) $(OBJS_DIR)/main.o
	$(CC) $(CFLAGS) $^ -o $@ -lm

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c
	$(CC) -c -I$(HDRS_DIR) $(CFLAGS) $< -o $@

unit_tests.exe: $(OBJS_TESTS_UNIT) $(OBJS)
	$(CC) -o $@ $^ $(ULINKS)

$(OBJS_DIR)/check_%.o: $(UNIT_DIR)/check_%.c $(HDRS_DIR)/*.h object_dir
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR)/%.o : $(UNIT_DIR)/%.c
	$(CC) -c -I$(HDRS_DIR) $(UFLAGS) $(CFLAGS) $< -o $@

$(OBJS_DIR)/%.d : $(SRCS_DIR)/%.c
	echo -n $(OBJS_DIR)/ > $@ && $(CC) -I$(HDRS_DIR) -M $< >> $@

$(OBJS_DIR)/%.d : $(UNIT_DIR)/%.c
	echo -n $(OBJS_DIR)/ > $@ && $(CC) -I$(HDRS_DIR) -M $< >> $@

include $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.d)
include $(UNIT_SRCS:$(UNIT_DIR)/%.c=$(OBJS_DIR)/%.d)

unit: unit_tests.exe
	@./$^

release: CFLAGS += -O2
release: app.exe
 
debug: CFLAGS += -ggdb
debug: app.exe
 
coverage: CFLAGS += --coverage
coverage: func
coverage:
	gcovr -r ./

object_dir:
	mkdir -p $(OBJS_DIR)

func: app.exe
	@cd ./func_tests/scripts && bash ./func_tests.sh

clean:
	$(RM) $(OBJS_DIR)/* *.exe ./func_tests/scripts/*.txt
	$(RM) -r $(OBJS_DIR)
