all: HelloWorld

myprog: HelloWorld.c
	gсс -Wall -Werror -o HelloWorld HelloWorld.c
clean:
	rm HelloWorld
run:
	./HelloWorld
