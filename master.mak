CC = g++
CFLAGS = -g -Wall -Werror -std=c++11
VPATH = db:tests
INCLUDE_DIR := db
SOURCE_FILES :=
TEST_SOURCE_FILES :=
MAIN_SOURCE_FILES := sys-main.cpp

include db/module.mak
include tests/module.mak

TEST_BINARIES = $(TEST_SOURCE_FILES:.cpp=.t)
OBJ_FILES = $(SOURCE_FILES:.cpp=.o)
LIBS = -lsqlite3

BIN := sys-main

CLEAN_FILES := $(BIN)
CLEAN_FILES += $(OBJ_FILES)
CLEAN_FILES += $(TEST_BINARIES)

$(BIN): $(OBJ_FILES) $(MAIN_SOURCE_FILES)
	$(CC) $(CFLAGS) -o$(BIN) -I$(INCLUDE_DIR) $(MAIN_SOURCE_FILES) $(OBJ_FILES) $(LIBS)

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

.cpp.t:
	$(CC) $(CFLAGS) -o $@ -I$(INCLUDE_DIR) $< $(OBJ_FILES)

.PHONY: clean
clean:
	rm -f $(CLEAN_FILES) *.db

.PHONY: check
check: $(OBJ_FILES) $(TEST_BINARIES)
	./$(TEST_BINARIES)
