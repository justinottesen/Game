main: bin
	clang-format -style=file -i src/*.cpp
	g++ src/main.cpp -std=c++20 -Wall -Wextra -Werror -o bin/a.out
	./bin/a.out

bin:
	mkdir -p bin

clean:
	rm -rf bin