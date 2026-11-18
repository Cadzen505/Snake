ALL_THE_OS = Snake.o Move.o
THE_DOT_HS = Snake.h Move.h
all: Main

%.o: %.cpp
	g++ -g -Wall -std=c++11 -Wpedantic -Wextra -Werror -c $< -o $@

Main: Main.o $(ALL_THE_OS) $(THE_DOT_HS)
	 g++ -o Main Main.o $(ALL_THE_OS)

clean:
	rm -f *.o Main 