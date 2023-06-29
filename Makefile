main: bin
	clang-format -style=file -i src/*.cpp
	clang-tidy src/main.cpp --quiet --format-style=file --
	g++ src/main.cpp -std=c++20 -Wall -Wextra -Werror -o bin/game

run:
	./bin/game

bin:
	mkdir -p bin

clean:
	rm -rf bin