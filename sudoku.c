#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "sudoku.h"

int L[3][9];
int S[9][9]; // la copie de la matrice complete
int T[9][9]; // la copie de la matrice de départ (S après enlever_case)
 
void copie(int M_cible[][9],int **M_acopier)
{

	for(int i=0;i<9;++i){
		for(int j=0;j<9;++j){
			int chiffre =M_acopier[i][j];
			M_cible[i][j]=chiffre;
		}
	}		
}

int* convert_gb(int x [2])
{	int taille_b=3;
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
{       int taille_b=3;
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

 //int** alea(){
 //int **alea=calloc(3,sizeof(int*));

 //}
                
                   
int taille( int* L){
	int k=0;
	for(int i=0;i<9;++i){
		if(L[i]!=0){
			k=k+1;
		}
	}
	return k;
}

bool nombre_is_correct(int nombre){
	if(nombre<1){return false;}
	if(nombre>9){return false;}
	return true;
}

bool ligne_is_correct(int ligne, int **M){
	int entier[9]={1,2,3,4,5,6,7,8,9};
	for(int j=0;j<9;++j){
		if(nombre_is_correct(M[ligne][j]) ) {
			entier[ M[ligne][j]-1]=0;
		}
	else{return false;}
}
	int sum_entier=0;
	for(int i=0;i<9;++i){ sum_entier=sum_entier+entier[i];}
	int sum_ligne=0;
	for(int j=0;j<9;++j){ sum_ligne=sum_ligne+M[ligne][j];}

	if( sum_entier!=0){ return false;}
	if (sum_ligne!=45){return false;}
	return true;
}





bool colonne_is_correct(int colonne,int **M){
	int entier[9]={1,2,3,4,5,6,7,8,9};
	for(int i=0;i<9;++i){
		if( nombre_is_correct(M[i][colonne]) ) {
			entier[ M[i][colonne]-1]=0;
		}
	else{return false;}
	}

	int sum_entier=0;
	for(int i=0;i<9;++i){ sum_entier=sum_entier+entier[i];}

	int sum_colonne=0;
	for(int i=0;i<9;++i){ sum_colonne=sum_colonne+M[i][colonne];}

	if( sum_entier!=0){ return false;}
	if (sum_colonne!=45){return false;}
	return true;
}







bool bloc_is_correct(int n_bloc,int **M)
{
	int entier[9]={1,2,3,4,5,6,7,8,9};

	for(int k=0;k<9;++k){
		int x[2]={n_bloc,k};
		int *l=convert_bg( x);
	
		if( nombre_is_correct(M[l[0]][l[1]]) ) {
		entier[ M[l[0]][l[1]]-1]=0;
		}
		else{return false;}
		free(l);
	
	}

	int sum_entier=0;
	for(int i=0;i<9;++i){ sum_entier=sum_entier+entier[i];}

	int sum_bloc=0;
	for(int k=0;k<9;++k){
		int x[2]={n_bloc,k};
		int *l = convert_bg( x);
 		sum_bloc=sum_bloc+M[l[0]][l[1]];
 	}

	if( sum_entier!=0){ return false;}
	if (sum_bloc!=45){return false;}
	return true;
}





bool matrice_is_correct(int **M){
	for(int i=0;i<9;++i){
		if(ligne_is_correct(i,M) ==false){return false;}
	}
	for(int j=0;j<9;++j){
		if(colonne_is_correct(j,M) ==false){return false;}
	}	
	for(int k=0;k<9;++k){
		if(bloc_is_correct(k,M) ==false){return false;}
	}
	return true;
	
}

bool point_is_correct(int i, int j,int **M, int s[9][9]){
	if(M[i][j]!=s[i][j]){return false;}
	return true;
}

int *complementaire( int *L,int taille){
	int M[9]={1,2,3,4,5,6,7,8,9};
	for (int i=0; i<9; ++i){   // on met à 0 les valeurs communes de L avec la listes {1,...,9}
		M[ L[i]-1]= 0;
	}

	int taille_completaire=9-taille;
	int *L2=calloc(9,sizeof(int));

	int k=0; // indice de la liste qu'on renvoie
	for(int j=0;j<9;++j){
		if (M[j]!=0){
		L2[k]=M[j];
		k=k+1;
		}
	}
	return L2;
}


int ** creer_bloc(int taille)
{
	int **MATRICE=calloc(taille,sizeof(int *));

	for(int i=0;i<taille;++i){
		MATRICE[i]=calloc(taille,sizeof(int));
	} 
	return MATRICE;
}



int *intersection(int* L1, int* L2,int taille_L1,int taille_L2)
{
	int *inter =calloc(9,sizeof(int));
	int indice_inter=0;
	int i=0;


	for(int i=0;i<taille_L1;++i){
		for(int j=0;j<taille_L2;++j){
			if (L1[i]==L2[j]){
			
			inter[indice_inter]=L1[i];
			indice_inter=indice_inter +1;

			}
		}

	} 
	return inter;
}






int *Ligne_Libre(int i, int**M)
{
	int *L=calloc(9,sizeof(int));
	int indice_L=0;
	for(int j=0;j<9;++j){
		if(M[i][j]!=0){
			L[indice_L]=M[i][j];
			indice_L=indice_L+1;
		}
	}
// L[0]=indice_L; 
	return complementaire(L,indice_L);
}








int *Colonne_Libre(int j, int **M)
{
	int *c=calloc(9,sizeof(int));
	int indice_C=0;
	for(int i=0;i<9;++i){
		if(M[i][j]!=0){
			c[indice_C]=M[i][j];
			indice_C=indice_C+1;
		}
	}
	// C[0]=indice_C; 
	return complementaire(c,indice_C);
}


//void remplir_case( int **M,int i,int j,int valeur)
//{
//	M[i][j]=valeur;
//}




void afficher_liste(int* L,int taille) // pour un pointeur
{
	for (int i=0;i<taille;++i){
		printf("%d \n ",L[i]);
	}
}


int *liste_alea1()
{
	int* L=calloc(9,sizeof(int));
	int entier[9]={1,2,3,4,5,6,7,8,9};
	int indice_L=0;
	while(indice_L<9){
		int alea=rand()%9+1;
		if (entier[ alea-1]!=0){
			L[indice_L]=alea;
			indice_L=indice_L+1;
			entier[alea-1]=0;
		}
	}	
	return L;
}

void afficherliste(int entier[9]){ // pour une liste (pas pointeur)
	for(int i=0;i<9;++i){
		printf("%d",entier[i]);
	}
}


void remplir_bloc_diagonale(int **M,int n_bloc)
{
	//int *l_a=liste_alea();
	int *l1=liste_alea1();
	for(int k=0;k<9;++k){
		int x[2]={n_bloc,k};
        	int *l= convert_bg( x);
		M[l[0]][l[1]]=l1[k];
		free(l);
	}
	free(l1);	
}

void print_ligne()
{
	printf("\n");
	for (int i=0; i<28;++i) {printf("_");}
}



void afficher_matrice(int **M)
{
	for(int i=0; i<9;++i)
	{
		for(int j=0;j<9;++j)
		{
			int chiffre = M[i][j];
			if (chiffre == 0) { printf(".  "); }
			else
			{
				if (T[i][j]==0) {printf("\x1B[31m");} //Si c'est une case qui était vide au début, passe la couleur au rouge.
				printf("%d  ",chiffre);
				printf("\033[0m"); //Passe la couleur au noir
			}
			if (j==2 || j==5) {printf("|");}
		}
		
		if (i==2 || i==5) {print_ligne();}
		printf("\n");
	}
	printf("\n\n");
}


//Ne sert que pour les tests: afficher la matrice remplie qui a été copiée.

void afficher_matrice2(int matrice[9][9] )
{
	for(int i=0; i<9;++i){
		for(int j=0;j<9;++j){
			printf("%d  ",matrice[i][j]);
		}
		printf("\n");
	}
}



int *Bloc_Libre(int n_bloc,int **M)
{
	int *b=calloc(9,sizeof(int));
	int indice_B=0;

	for(int k=0;k<9;++k){
		int x[2]={n_bloc,k};
	        int *l=convert_bg( x);
		int i=l[0];
		int j=l[1];	
		if( M[i][j]!=0){
			b[indice_B]=M[i][j];
			indice_B=indice_B+1;
		}
	}
	return complementaire(b,indice_B);
}




int trouver_chiffre(int **M,int n_bloc,int k)
{
	int x[2]={n_bloc,k};
	int *l=convert_bg( x);	       
	int *ligne=Ligne_Libre(l[0],M);
	int *colonne=Colonne_Libre(l[1],M);
	int *bloc=Bloc_Libre(n_bloc,M);
	int *intersect1= intersection(ligne,colonne,taille(ligne),taille(colonne));
	int *intersect= intersection(intersect1,bloc,taille(intersect1),taille(bloc));
	free(l);
	int len=taille(intersect);
	if(len!=0){
		int alea=rand()%len+1;
		//printf("alea %d \n",alea);
		return intersect[alea-1];
	}
	return intersect[0];
}


bool bloc_rempli(int n_bloc,int **M)
{
	for(int k=0;k<9;++k){
		int x[2]={n_bloc,k};
		int *l=convert_bg( x);
		if(M[l[0]][l[1]]==0){
			return false;
		}
	}
	return true;
}


bool ligne_rempli(int i,int **M)
{
	for(int j=0;j<9;++j){
		if(M[i][j]==0){
			return false;
			}
		}
	return true;		
}

void remplir_ligne(int i,int **M){
	int iter=0;
	while(ligne_rempli(i,M)==false && iter<500){
		for(int j=0;j<9;++j){
			if(M[i][j]==0){
			int x[2]={i,j};
			int *l=convert_gb( x);
			int chiffre= trouver_chiffre(M,l[0],l[1]);
			M[i][j]=chiffre;
			}
		}	
	}		
}

void bloc_a_zero(int n_bloc,int**M)
{
	for(int k=0;k<9;++k){
		int x[2]={n_bloc,k};
		int *l=convert_bg( x);
		M[l[0]][l[1]]=0;
	}
}	

	
void remplir_bloc_non_diagonale(int n_bloc,int **M)
{
	int iter=0;
	while(bloc_rempli(n_bloc,M)!= true && iter<100){
		bloc_a_zero(n_bloc,M);
		
		for(int k=0;k<9;++k){
			int chiffre= trouver_chiffre(M,n_bloc,k);
			int x[2]={n_bloc,k};
			int *l=convert_bg( x);
			M[l[0]][l[1]]=chiffre;
			//printf("%d \n",chiffre);
			free(l);
		}
		++iter;
	}
	 //printf("n iter: %d \n ",iter);	
}	

bool matrice_rempli(int **M)
{
	for(int i=0;i<9;++i){
		if(bloc_rempli(i,M)==false){return false;}
	}
	return true;	
}



void remplir_matrice(int **M)
{
	remplir_bloc_diagonale(M,0);
	remplir_bloc_diagonale(M,4);
	remplir_bloc_diagonale(M,8);
	while(matrice_rempli(M)==false){
	bloc_a_zero(1,M);
	bloc_a_zero(2,M);
	bloc_a_zero(3,M);
	bloc_a_zero(5,M);
	bloc_a_zero(6,M);
	bloc_a_zero(7,M);
	remplir_bloc_non_diagonale(1,M);
	remplir_bloc_non_diagonale(2,M);
	remplir_bloc_non_diagonale(3,M);
	remplir_bloc_non_diagonale(5,M);
	remplir_bloc_non_diagonale(6,M);
	remplir_bloc_non_diagonale(7,M);
	}
}



void enlever_case(int nombre,int **M)
{
	int k=0;
	while(k<nombre){
		int i=rand()%9;
		int j=rand()%9;
		if(M[i][j]=!0){
		M[i][j]=0;
		++k;
		}
	}
}
	
int ** generer()
{
	int **M= creer_bloc(9);
	remplir_matrice(M);
	return M;
}

int* trouver_erreur(int **M){
	int *e=calloc(2*81,sizeof(int));
	int nombre_erreur=0;
	for(int i=1;i<10;++i){
		for(int j=1;j<10;++j){
			if(point_is_correct(i-1,j-1,M,S)==false){
					e[2*nombre_erreur]=i;
					e[2*nombre_erreur+1]=j;
					++nombre_erreur;
			}		
		}			
	}
	return e;		
}

void afficher_erreur(int *erreur)
{
	int nombre_erreur= (taille(erreur))*0.5;
	printf("nombre erreur : %d \n ", nombre_erreur);
	for(int k=0;k<nombre_erreur;++k){
		int i=erreur[2*k];
		int j=erreur[2*k+1];
		printf("erreur n°%d : ligne:%d , colonne: %d",k+1,i,j);
	}	
} 

void jouer(int **M)
{
	while(matrice_rempli(M)==false){
		system(" clear");
		afficher_matrice(M);
		int ligne;
		int colonne;
		int valeur;
		printf("Entrez votre réponse \n ");
		printf("entrez numéro de ligne de 1 à 9: ");
		scanf("%d",&ligne);
		printf("entrez numéro de colonne de 1 à 9:  ");
		scanf("%d",&colonne);
		printf("\n");
		printf("entrez la valeur: ");
		scanf("%d",&valeur);
		printf("\n");
		printf("ok");
		if ( valeur>0 && valeur<10){
			M[ ligne -1][colonne -1]= valeur;
		}
		else{ printf("erreur , le nombre n'est pas correct");}
		//afficher_matrice(M);
	}
	if(matrice_rempli(M)==true){ system("clear"); afficher_matrice(M);}
	
	int fini=0;
	
	
	while(fini==0){
		printf(" avez-vous finis? tapez 1 pour oui ou 0 pour non: ");
		scanf("%d",&fini);
		if(fini==0){
			system(" clear");
			afficher_matrice(M);
			int ligne;
			int colonne;
			int valeur;
			printf("Entrez votre réponse \n ");
			printf("entrez numéro de ligne de 1 à 9: ");
			scanf("%d",&ligne);
			printf("entrez numéro de colonne de 1 à 9:  ");
			scanf("%d",&colonne);
			printf("\n");
			printf("entrez la valeur: ");
			scanf("%d",&valeur);
			printf("\n");	
			if ( valeur>0 && valeur<10){
				M[ ligne -1][colonne -1]= valeur;
			}
			else{ printf("erreur , le nombre n'est pas correct");}
			//afficher_matrice(M);
		}
	}
	bool correct= matrice_is_correct(M);
	if(correct==true){ printf("sudoku correct \n ");}
	else
	{
		printf("sudoku incorrect");
		int *erreur =trouver_erreur(M);
		afficher_erreur(erreur);
	}
}



//void copie2(int **M)
//{
//	for(int i=0;i<9;++i){
//		for(int j=0;j<9;++j){
//			int chiffre =M[i][j];
//			S[i][j]=chiffre;
//		}
//	}		
//}


void m_sudoku()
{
	srand( time( NULL ) );
	int **M=generer(); // on genere le sudoku
	copie(S,M); // on copie la matrice complete 
	enlever_case(2,M);
	copie(T,M); // on copie la matrice à remplir 
	printf("\n");
	afficher_matrice(M);
	printf("\n \n");
	//afficher_matrice2(S);
	jouer(M);
	free(M);
}











