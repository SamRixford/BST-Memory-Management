PJ3	:main.o util.o BST.o MM.o
	 g++ -Wall -o PJ3 main.o util.o BST.o MM.o

main.o	:main.cpp data_structures.h util.h BST.h MM.h
	 g++ -Wall -c main.cpp

util.o	:util.cpp data_structures.h util.h
	 g++ -Wall -c util.cpp

BST.o	:BST.cpp data_structures.h BST.h
	 g++ -Wall -c BST.cpp

MM.o    :MM.cpp data_structures.h MM.h
	 g++ -Wall -c MM.cpp

clean	:
	rm *.o PJ3
