BIN = bin
OBJ = obj
SRC = src
INC = include

SRCS = $(wildcard $(SRC)/*.c)
OBJS = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))

CC = clang
CFLAGS = -g -Wall -O -std=c11 -I$(INC) 
LDLIBS = -lm
RM = $(BIN)/main $(OBJ)/*.o *.png

.PHONY: default clean

default: test.png

test.png: out.txt
	python main.py

out.txt : $(BIN)/main
	./$^ > $@

$(BIN)/main: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LDLIBS)

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LDLIBS)

clean:
	rm -rf $(RM)
