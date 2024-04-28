CXX := clang

all: a b

a: src/a.c
	$(CXX) -o bin/a -g src/a.c

b: src/b.c
	$(CXX) -o bin/b -g src/b.c

run: clean all
	clear
	./bin/a
	./bin/b

clean:
	-rm ./bin/*

setup:
	@mkdir -p bin src
