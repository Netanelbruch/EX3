FLAG = -Wall -g
CC = gcc



.PHONY: all clean

all: isort txtfind

isort: isort.c
	gcc FLAG-o isort isort.c

txtfind: txtfind.c
	gcc FLAG -o txtfind txtfind.c

clean:
	rm -f *.o txtfind isort