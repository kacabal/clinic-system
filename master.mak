CC = g++
CFLAGS = -g -Wall -Werror -std=c++11
VPATH = db
INCLUDE_DIR := db
SOURCE_FILES :=
MAIN_SOURCE_FILES := sys-main.cpp

include db/module.mak

OBJ_FILES = $(SOURCE_FILES:.cpp=.o)
LIBS = -lsqlite3

CLEAN_FILES := $(OBJ_FILES)
BIN := sys-main

$(BIN): $(OBJ_FILES) $(MAIN_SOURCE_FILES)
	$(CC) $(CFLAGS) -o$(BIN) -I$(INCLUDE_DIR) $(MAIN_SOURCE_FILES) $(OBJ_FILES) $(LIBS)

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(CLEAN_FILES) $(BIN) *.db
