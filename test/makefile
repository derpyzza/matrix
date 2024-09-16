CC=clang
SRC=src
OBJ=bin
PROG_NAME = $(OBJ)/test

CFLAGS := -Wall -pedantic -g
LIB := ../libmatrix.a

all: $(OBJ) test

$(OBJ):
	mkdir -p ./$(OBJ)

INCLUDE_FILES = -Itest.h -I../src/ -I../src/matrix_debug/matrix_debug.h

SRC_FILES := ./test.c
SRC_FILES += $(addprefix $(SRC)/tests_, vec2.c vec3.c vec4.c mat.c)
OBJ_FILES := $(addprefix $(OBJ)/, $(notdir $(SRC_FILES:.c=.o)))

test: $(PROG_NAME)
	$^

$(PROG_NAME): $(OBJ_FILES)
	$(CC) $^ -o $(PROG_NAME) $(CFLAGS) $(INCLUDE_FILES) $(LIB) -lm

$(OBJ)/%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS) $(INCLUDE_FILES)


$(OBJ)/%.o: $(SRC)/%.c
	$(CC) -c $< -o $@ $(CFLAGS) $(INCLUDE_FILES)

clean:
	rm -rf $(OBJ)/*

.PHONY: all clean
