CC = g++
CFLAGS = -g -Wall -std=c++11
VPATH = db
INCLUDE_DIR := db
SOURCE_FILES :=

include db/module.mak

OBJ_FILES = $(SOURCE_FILES:.cpp=.o)

CLEAN_FILES := $(OBJ_FILES)
BIN := sys-main

$(BIN): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o$(BIN) -I$(INCLUDE_DIR) sys-main.cpp $(OBJ_FILES)

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(CLEAN_FILES) $(BIN)
