
CC := gcc
CFLAGS := -Wall -std=c99
OFLAGS := -g

ifeq ($(DEBUG), 1)
	DFLAGS := -D_DEBUG
else
	DFLAGS :=
endif

BIN_DIR := ./bin
OBJ_DIR := ./objects
INC_DIR := ./include
SRC_DIR := ./src

JAKEH_OBJS := $(OBJ_DIR)/jakeh.o $(OBJ_DIR)/cmdstring.o

all: $(BIN_DIR)/jakeh

$(BIN_DIR)/jakeh: $(JAKEH_OBJS)
	$(CC) $(CFLAGS) $(JAKEH_OBJS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -I $(INC_DIR) $(CFLAGS) $(OFLAGS) $(DFLAGS) $^ -c -o $@

