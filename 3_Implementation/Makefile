PROJ_NAME = MrBean_Wire_Loop_Game
TEST_PROJ_NAME = Test_$(PROJ_NAME)

SRC = src/show_info.c \
src/show_menu.c \
src/score_log.c \
src/change_setting.c \
src/level_pattern.c \
src/start_game.c \
src/clear.c \

COV_SRC = test_move.c

TEST_SRC = test/test_main.c \
test/test_move.c \
test/test_level_pattern.c \
unity/unity.c \

INC_H = inc
INC_T = unity

ifdef OS
   RM = del 
   FixPath = $(subst /,\,$1)
   EXEC = exe
else
   ifeq ($(shell uname), Linux)
      RM = rm -rf
      FixPath = $1
	  EXEC = out
   endif
endif
.PHONY: run clean test doc all

all:
	gcc -I $(INC_H) $(SRC) project_main.c -o build/$(call FixPath,$(PROJ_NAME).$(EXEC))
	
run:
	build/$(call FixPath,$(PROJ_NAME).$(EXEC))
test:
	gcc -I $(INC_H) -I $(INC_T) $(TEST_SRC) -o $(call FixPath,$(TEST_PROJ_NAME).$(EXEC))
	./$(call FixPath,$(TEST_PROJ_NAME).$(EXEC))

coverage:
	gcc -fprofile-arcs -ftest-coverage -I $(INC_H) -I $(INC_T) $(TEST_SRC) -o $(call FixPath, $(TEST_PROJ_NAME).$(EXEC))
	./$(call FixPath,$(TEST_PROJ_NAME).$(EXEC))
	gcov -a $(COV_SRC)
	$(RM) *.$(EXEC)
	$(RM) *.gcda
	$(RM) *.gcno
	$(RM) *.c.gcov
	$(RM) *.DAT
	
cppcheck:
	cppcheck --enable=all $(SRC) project_main.c
debug:
	gcc -I $(INC_H) $(SRC) project_main.c -g -o build/$(PROJ_NAME).$(EXEC)
	gdb build/$(PROJ_NAME).$(EXEC)

valgrind:
	valgrind ./$(TEST_PROJ_NAME).$(EXEC)


clean:
	$(RM) *.DAT
	$(RM) *.$(EXEC)
	$(RM) *.gcda
	$(RM) *.gcno
	$(RM) *.c.gcov
