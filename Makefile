PROJ_NAME = game
TEST_PROJ_NAME = Test_$(PROJ_NAME)

SRC = src/show_info.c \
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

all:
	echo hello!
	
	
