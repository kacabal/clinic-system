CC = g++
CFLAGS = -g -Wall
VPATH = db
INCLUDE_DIR := db

include db/module.mak

CLEAN_FILES := $(DB_OBJS)
BIN := karl

$(BIN): $(DB_OBJS)
	$(CC) $(CFLAGS) -o$(BIN) -I$(INCLUDE_DIR) sys-main.cpp $(DB_OBJS)


clean:
	rm -f $(CLEAN_FILES) $(BIN)
