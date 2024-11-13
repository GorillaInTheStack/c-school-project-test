SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, obj/%.o, $(SRC))

all: bin/bin.exe run

obj/%.o: %.c
	gcc -g -c $< -o $@

bin/bin.exe: $(OBJ)
	gcc -o bin/bin.exe $(OBJ)

clean:
	rm -f obj/*.o bin/bin.exe

run: bin/bin.exe
	chmod +x bin/bin.exe
	./bin/bin.exe
