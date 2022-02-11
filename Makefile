all: hello
hello: hello.c
	gсс -Wall -Werror -o hello hello.c
clean:
	rm hello
run:
	./hello
