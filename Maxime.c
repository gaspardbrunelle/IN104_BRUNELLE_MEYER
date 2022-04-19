#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define taille 9
#define taille_b 3

int ** creer_bloc()
{
	int **M=calloc(taille,sizeof(int *));

	for(int i=0;i<taille;++i)
	{
		M[i]=calloc(taille,sizeof(int));
	} 
	return M;
}


int *intersection(int* L1, int* L2,int len_L1,int len_L2)
{
	int *inter = malloc(taille*sizeof(int));
	int indice_inter=0;
	int i=0;


	for(int i=0;i<len_L1;++i)
	{
		for(int j=0;j<len_L2;++j)
		{
			if (L1[i]==L2[j])
			{
			indice_inter=indice_inter +1;
			inter[indice_inter]=L1[i];
			}
		}
	}
	inter[0]=indice_inter; 
	return inter;
}


int *Ligne_Libre(int i, int**M)
{
	int *L=calloc(taille,sizeof(int));
	int indice_L=0;
	for(int j=0;j<taille;++j)
	{
		if(M[i][j]!=0)
		{
			indice_L=indice_L+1;
			L[indice_L]=M[i][j];
		}
	}
	// L[0]=indice_L; 
	return L;
}


int *Colonne_Libre(int j, int **M)
{
	int *C=calloc(taille,sizeof(int));
	int indice_C=0;
	for(int i=0;i<taille;++i)
	{
		if(M[i][j]!=0)
		{
			indice_C=indice_C+1;
			C[indice_C]=M[i][j];
		}
	}
	// C[0]=indice_C; 
	return C;
}


int *complementaire( int *L,int len_L)
{
	int M[taille]
	for (int i=0 ; i<taille ; i++) {M[i]=i+1;}
	//int M[9]={1,2,3,4,5,6,7,8,9};
	
	for (int i=0; i<len_L; ++i)
	{   // on met à 0 les valeurs communes de L avec la listes {1,...,9}
		M[ L[i]-1]= 0;
	}

	int *L2=calloc(taille,sizeof(int));

	int k=0; // indice de la liste qu'on renvoie
	for(int j=0;j<taille;++j)
	{
		if (M[j]!=0)
		{
			L2[k]=M[j];
			k=k+1;
		}
	}
	return L2;
}


int len( int* L)
{
	int k=0;
	for(int i=0;i<9;++i)
	{
		if(L[i]!=0) {k=k+1;}
	}
	return k;
}


void afficher_liste(int* L,int len_L)
{
	for (int i=0;i<len_L;++i)  { printf("%d \n ",L[i]); }
}


int* convert_gb(int x [2])
{
	int num_bloc = x[1]/taille_b + (x[0]/taille_b)*taille_b;
	int colonne_bloc = num_bloc % taille_b;
	int ligne_bloc = num_bloc / taille_b;
	
	int colonne_dans_bloc = x[1] - colonne_bloc*taille_b;
	int ligne_dans_bloc = x[0] - ligne_bloc*taille_b;
	int num_dans_bloc = colonne_dans_bloc + taille_b*ligne_dans_bloc;
	
	int* tab = malloc(2*sizeof(int));
	tab[0] = num_bloc;
	tab[1] = num_dans_bloc;
	
	return tab;
}


int* convert_bg(int x [2])
{
	int colonne_bloc = x[0] % taille_b;
	int ligne_bloc = x[0] / taille_b;
	int colonne_dans_bloc = x[1] % taille_b;
	int ligne_dans_bloc = x[1] / taille_b;
	
	int i = ligne_dans_bloc + ligne_bloc*taille_b;
	int j = colonne_dans_bloc + colonne_bloc*taille_b;
	
	int* tab = malloc(2*sizeof(int));
	tab[0] = i;
	tab[1] = j;
	
	return tab;
}

