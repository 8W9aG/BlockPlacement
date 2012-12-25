blockplacement: clear main.o BlockPlacement.o
	g++ main.o BlockPlacement.o -o example

clear:
	rm -f *.o
	rm -f example

main.o:
	g++ -c main.cpp -o main.o

BlockPlacement.o:
	g++ -c BlockPlacement.cpp -o BlockPlacement.o
