all:
	rm main
	g++ -std=c++14 -Wall -I/usr/include main.cpp funcs.cpp gui.cpp game.cpp logic.cpp -o main -lsfml-graphics -lsfml-window -lsfml-system 
	./main
	