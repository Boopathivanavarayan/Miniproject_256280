PROJ_NAME = Mr_Bean's_Wire_Loop_Game
TEST_PROJ_NAME = Test_$(PROJ_NAME)

SRC =src/show_info.c \
src/show_menu.c \
src/score_log.c \
src/change_setting.c \
src/level_pattern.c \
src/start_game.c \
src/clear.c 


TEST_SRC = test/test_level_pattern.c \
test/test_move.c \
test/test_main.c \
unity/unity.c 
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
	gcc -I $(INC_H) $(SRC) project_main.c -o $(call FixPath,$(PROJ_NAME).$(EXEC))
	
