main: bin
	clang-format -style=file -i src/*.cpp src/*.h
	clang-tidy src/*.cpp src/*.h --quiet --format-style=file -- -x c++
	g++ src/*.cpp -std=c++20 -Wall -Wextra -Werror -o bin/game
	./bin/game

bin:
	mkdir -p bin

clean:
	rm -rf bin