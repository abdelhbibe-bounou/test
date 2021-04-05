Optim : main.o Solveur.o
	g++ -o Optim main.o Solveur.o
main.o : main.cpp Solveur.hpp
	g++ -Wall -c main.cpp
MD.o : Solveur.cpp Solveur.hpp
	g++ -Wall -c Solveur.cpp            

