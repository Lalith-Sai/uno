output: main.o gameData.o
		g++ main.o gameData.o -o run

main.o: main.cpp
		g++ -c main.cpp -std=c++11

gameData.o: gameData.cpp gamedata.h
		g++ -c gameData.cpp -std=c++11

clean:
	rm *.o run
