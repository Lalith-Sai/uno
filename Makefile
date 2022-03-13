output: main.o gameData.o
		g++ main.o gameData.o -o run

main.o: main.cpp
		g++ -c main.cpp 

gameData.o: gameData.cpp gamedata.h
		g++ -c gameData.cpp 

clean:
	rm *.o run
