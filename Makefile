NAME := Snake-game
CC := gcc
FLAGS := -Wall -Werror -Wextra -g
LIBS := -lncurses

SRC_DIR := src
INC_DIR := $(SRC_DIR)/header\ files
OBJ_DIR := release

SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

.PHONY: all clean

all: $(OBJ_DIR)/$(NAME)

$(OBJ_DIR)/$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	/bin/rm -rf $(OBJ_DIR)

.PHONY: all clean
