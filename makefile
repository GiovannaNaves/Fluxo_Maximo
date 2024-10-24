CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
CFLAGS = -Wall -c -I$(INC)
LFLAGS = -Wall -I$(INC)
OBJS = $(OBJ)/main.o $(OBJ)/grafo.o
HDRS = $(INC)/grafo.hpp

EXE = $(BIN)/main

all: $(EXE) run

$(EXE): $(OBJS)
	$(CC) $(LFLAGS) -o $(EXE) $(OBJS) $(LIBS)

$(OBJ)/main.o: $(SRC)/main.cpp $(HDRS)
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/grafo.o: $(SRC)/grafo.cpp $(HDRS)
	$(CC) $(CFLAGS) -o $(OBJ)/grafo.o $(SRC)/grafo.cpp

run: $(EXE)
	./$(EXE)

clean:
	rm -f $(EXE) $(OBJS)
