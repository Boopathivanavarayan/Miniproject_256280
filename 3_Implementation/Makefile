# Name of the project
PROJECT_NAME = game

# Output directory
BUILD = build

# All source code files
SRC = src/show_info.c \
src/show_menu.c \
src/score_log.c \
src/change_setting.c \
src/level_pattern.c \
src/start_game.c \
src/clear.c \

# All test source files
TEST_SRC = ${SRC}\
test/test_level_pattern.c\
test/test_move.c\
test/test_main.c\
unity/unity.c\

TEST_OUTPUT = $(BUILD)/Test_$(PROJECT_NAME)

# All include folders with header files
INC	= -Iinc\
-Iunity\

#Library Inlcudes
INCLUDE_LIBS = 

# Project Output name
PROJECT_OUTPUT = $(BUILD)/$(PROJECT_NAME)

# Document files
DOCUMENTATION_OUTPUT = documentation/html

# Default target built
$(PROJECT_NAME):all

# Run the target even if the matching name exists
.PHONY: run clean test doc all

all: $(SRC) $(BUILD)
	gcc project_main.c $(SRC) $(INC) -o $(PROJECT_OUTPUT).out

# Call `make run` to run the application
run:$(PROJECT_NAME)
	./$(PROJECT_OUTPUT).out

# Document the code using Doxygen
doc:
	make -C ./documentation

# Build and run the unit tests
test:$(BUILD)
	gcc $(TEST_SRC) $(INC) -o $(TEST_OUTPUT) $(INCLUDE_LIBS)
	./$(TEST_OUTPUT)

# Remove all the built files, invoke by `make clean`
clean:
	rm -rf $(BUILD) $(DOCUMENTATION_OUTPUT) contacts.bin

# Create new build folder if not present
$(BUILD):
	mkdir build