endfile: interface_graphique.o sudoku.o pacman.o morpion.o
	gcc -o endfile interface_graphique.o sudoku.o pacman.o morpion.o
	


	
	
sudoku.o :  sudoku.c sudoku.h
	gcc  -o sudoku.o -c sudoku.c 
	
	
pacman.o :  pacman.c pacman.h
	gcc  -o pacman.o -c pacman.c 
	
morpion.o :  morpion.c morpion.h
	gcc  -o morpion.o -c morpion.c 
	

interface_graphique.o :  interface_graphique.c sudoku.h pacman.h morpion.h
	gcc  -o interface_graphique.o -c interface_graphique.c 
			
	
	
	
