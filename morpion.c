#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "morpion.h"




int grille [3][3];

void remplir_grille( int grille[3][3])
{
	for(int i=0;i<3;++i)
	{
		for(int j=0;j<3;++j)
		{
			grille[i][j]=0; // vide
		}	
	}
}

void afficher_grille( int grille[3][3])
{
	for(int i=0;i<3;++i)
	{
		for(int j=0;j<3;++j)
		{
			if( grille[i][j]==0)
			{
				printf(". ");
			}
			
			else if(grille[i][j]==1)
			{	
				printf("x ");
			}
			else
			{
				printf("o ");
			}
		}
		printf(" \n");
		
	}
	printf(" \n");
	
}



void placer_chiffre(int grille[3][3],int ligne,int colonne,int joueur )
{
	grille[ligne][colonne]=joueur;
}


void chiffre_alea(int grille[3][3])
{
	bool placer= false;
	while(!placer)
	{
		int ligne_alea=rand()%3;
		int colonne_alea=rand()%3;
		if( grille[ligne_alea][colonne_alea]==0  ) // si c'est vide
		{
			grille[ligne_alea][colonne_alea]=2;
			placer=true;
		}
	}	
}



bool joueur_gagne( int grille[3][3],int joueur)
{
	bool gagne=false;
	
        if (grille[0][0]==joueur && grille[0][1]==joueur && grille[0][2]==joueur ){ gagne=true;}
        else if (grille[1][0]==joueur && grille[1][1]==joueur && grille[1][2]==joueur ){ gagne=true;}
        else if (grille[2][0]==joueur && grille[2][1]==joueur && grille[2][2]==joueur ){ gagne=true;}
        
        else if (grille[0][0]==joueur && grille[1][0]==joueur && grille[2][0]==joueur ){ gagne=true;}
        else if (grille[0][1]==joueur && grille[1][1]==joueur && grille[2][1]==joueur ){ gagne=true;}
        else if (grille[0][2]==joueur && grille[1][2]==joueur && grille[2][2]==joueur ){ gagne=true;}
        
        else if (grille[0][0]==joueur && grille[1][1]==joueur && grille[2][2]==joueur ){ gagne=true;}
        else if (grille[2][0]==joueur && grille[1][1]==joueur && grille[0][2]==joueur ){ gagne=true;}
                                               
        return gagne;
                                               
} 		
	
	
bool plein( int grille[3][3])
{
	bool plein= true;
	
	for(int i=0;i<3;++i)
	{
		for(int j=0;j<3;++j)
		{
			if( grille[i][j]== 0)
			{
			plein=false;
			}
		}
	}
	return plein;	
}

 

int demande_ligne()
{
	int c;
	printf("ligne : ");
        scanf("%d",&c);
        printf("\n");
        return c-1;
}    

int demande_colonne()
{
	int c;
	printf("colonne : ");
        scanf("%d",&c);
        printf("\n");
        return c-1;
}    
    	

void m_morpion()
{
	srand( time( NULL ) );
	remplir_grille(grille);

	bool fini= false;

	int nb_tours=0;
	

	while(!fini)
	{
	
		afficher_grille( grille);
	
	
		int ligne= demande_ligne();
		int colonne= demande_colonne();
	
	
		placer_chiffre(grille,ligne, colonne , 1);
	
		if (!plein(grille)) {
	            chiffre_alea(grille);
            
	        }
	        fini = joueur_gagne(grille,1) || joueur_gagne(grille,2) || plein(grille);
	        nb_tours = nb_tours +1;
	}
	
	// c'est fini
	afficher_grille(grille);
	if(joueur_gagne(grille,1) )
	{
	printf(" gagné en %d tours \n ", nb_tours);
	}
	
	else if(joueur_gagne(grille,2) )
	{
	printf(" perdu en %d tours \n  ", nb_tours);
	}
	
	else 
	{
	printf("égalité en %d tours \n",nb_tours);
	}
	
	
}	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	













					
		
