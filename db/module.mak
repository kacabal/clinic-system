CC = g++
CFLAGS = -g -Wall

DB_OBJS = DbInterface.o

db: $(DB_OBJS)

DbInterface.o: DbInterface.cpp DbInterface.h
	$(CC) $(CFLAGS) -c DbInterface.cpp
