#PROJETO LP1

PROG = Driver_Dicionario
CC = g++
CPPFLAGS = -O0 -g -W -Wall -std=c++11 -pedantic
OBJS = Driver_Dicionario.o 
HEADER = ./includes/Dicionario.hpp
SRC_DIR     = ./src/
BIN_DIR     = ./bin/

$(PROG): $(OBJS)
	$(CC) $(OBJS) -o $(PROG)
	rm *.o

Driver_Dicionario.o: $(HEADER)
	$(CC) $(CPPFLAGS) -c $(SRC_DIR)Driver_Dicionario.cpp
clean:
	rm -f $(PROG) 
