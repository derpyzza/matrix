CC=clang
SRC=src
OBJ=obj

CFLAGS := -Wall -pedantic
LDFLAGS :=

PROG_NAME = libmatrix

all: $(PROG_NAME)

INCLUDE_FILES = -I$(SRC)
# INCLUDE_FILES = -I$(SRC)/matrix.h -I$(SRC)/matrix_types.h

vec2.o: $(SRC)/types/matrix_vec2.c  
	$(CC) -c $< -o $(OBJ)/$@ $(CFLAGS) $(LDFLAGS) $(INCLUDE_FILES)
vec3.o: $(SRC)/types/matrix_vec3.c
	$(CC) -c $< -o $(OBJ)/$@ $(CFLAGS) $(LDFLAGS) $(INCLUDE_FILES)
vec4.o: $(SRC)/types/matrix_vec4.c
	$(CC) -c $< -o $(OBJ)/$@ $(CFLAGS) $(LDFLAGS) $(INCLUDE_FILES)
mat.o: $(SRC)/types/matrix_mat.c
	$(CC) -c $< -o $(OBJ)/$@ $(CFLAGS) $(LDFLAGS) $(INCLUDE_FILES)

matrix.o: $(SRC)/matrix.c
	$(CC) -c $< -o $(OBJ)/$@ $(CFLAGS) $(LDFLAGS) $(INCLUDE_FILES)

$(PROG_NAME): matrix.o mat.o vec2.o vec3.o vec4.o
	ar rcs libmatrix.a $(OBJ)/matrix.o $(OBJ)/mat.o $(OBJ)/vec2.o $(OBJ)/vec3.o $(OBJ)/vec4.o


clean:
	rm -rf $(OBJ) libmatrix.a
	mkdir $(OBJ)

.PHONY: all clean
