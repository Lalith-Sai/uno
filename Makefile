output: main.o gameData.o
		g++ main.o gameData.o -o run

main.o: main.cpp
		g++ -o main main.cpp 

gameData.o: gameData.cpp
		g++ -c gameData.cpp 

clean:
	rm *.o run
