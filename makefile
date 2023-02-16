


.PHONY: all clean

all: isort txtfind

isort: isort.c
	$(CC) $(FLAGS) isort.c -o isort -lm

txtfind: txtfind.c
	$(CC) $(FLAGS)txtfind.c -o txtfind -lm

clean:
	rm -f *.o txtfind isort