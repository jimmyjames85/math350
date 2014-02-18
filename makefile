all: math350.a

math350.a: math350.cpp
	g++ math350.cpp -o math350.a