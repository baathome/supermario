INC_DIR := lib/raylib/include
LIB_DIR := lib/raylib/lib
SRC := $(wildcard *.c)
OBJ := $(SRC:.c=.o)
EXE := supermario.exe

%.o: %.c
	gcc -c $< -I"$(INC_DIR)" -o $@

all: $(SRC)
	gcc $(OBJ) -L"$(LIB_DIR)" -lraylib -lopengl32 -lmingw32 -lgdi32 -lwinmm -o $(EXE)

clean:
	del *.exe
