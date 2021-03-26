all: build/app.exe

build/app.exe: intermediate/main.o
	g++ -o build/app.exe intermediate/main.o

intermediate/main.o: intermediate/main.s
	as -o intermediate/main.o intermediate/main.s

intermediate/main.s: intermediate/main.i
	g++ -S -o intermediate/main.s intermediate/main.i

intermediate/main.i: main.cpp
	cpp main.cpp > intermediate/main.i

clean:
	rm	intermediate/main.i	intermediate/main.s	intermediate/main.o	build/app.exe