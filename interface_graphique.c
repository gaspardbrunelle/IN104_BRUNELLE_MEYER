#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "pacman.h"
#include "sudoku.h"
#include "morpion.h"

bool recommencer()
{
	
	printf(" voulez vous continuer à jouer?  si oui, tapez 1 ,sinon tapez 2 \n");
	int c;
	scanf("%d",&c);
	bool bonne_touche= (c==1) || (c==2);
	while( !bonne_touche){
			system("clear");
			printf("pas la bonne touche. \n");
			printf(" voulez vous continuer à jouer?  si oui, tapez 1 ,sinon tapez 2 \n");
	
			int c;
			scanf("%d",&c);
			bool bonne_touche= (c ==1) || (c==2);
	}
	if(c==1)
	{
	return true;
	}
	else
	{
	return false;
	}
}			
	
	



int main()
{	
	bool fini_jouer=false;	
	while(!fini_jouer)
	{	
		system("clear");
		printf("pressez 1 pour jouer a sudoku \n pressez 2 pour jouer au pacman \n pressez 3 pour jouer au morpion \n ");

		int c;
		scanf("%d",&c);
		bool bonne_touche= (c ==1) || (c==2) || (c==3);
			
		while( !bonne_touche){
			system("clear");
			printf("pas la bonne touche. \n");
			printf("pressez 1 pour jouer a sudoku \n pressez 2 pour jouer au pacman \n pressez 3 pour jouer au morpion \n ");
	
			int c;
			scanf("%d",&c);
			bool bonne_touche= (c ==1) || (c==2) || (c==3);
		}	
			
		if(c==1){
			system("clear");
			m_sudoku();
			
		}
		if(c==2){
			system("clear");
			m_pacman();
		}
		if(c==3){
			system("clear");
			m_morpion();
		}
		fini_jouer= !recommencer(); // on demande si le joueur veut continuer a jouer
		
	}	
		
}

