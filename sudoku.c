#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int ** creer_bloc(int taille){

int **M=calloc(taille,sizeof(int *));

for(int i=0;i<taille;++i){
M[i]=calloc(taille,sizeof(int));
} 
return M;
}



int *intersection(int* L1, int* L2,int taille_L1,int taille_L2){
int *inter =malloc(9*sizeof(int));
int indice_inter=0;
int i=0;


for(int i=0;i<taille_L1;++i){
for(int j=0;j<taille_L2;++j){
if (L1[i]==L2[j]){
indice_inter=indice_inter +1;
inter[indice_inter]=L1[i];

}
}

}
inter[0]=indice_inter; 
return inter;
}






int *Ligne_Libre(int i, int**M){
int *L=calloc(9,sizeof(int));
int indice_L=0;
for(int j=0;j<9;++j){
if(M[i][j]!=0){
indice_L=indice_L+1;

L[indice_L]=M[i][j];
}
}
// L[0]=indice_L; 
return L;
}








int *Colonne_Libre(int j, int **M){
int *C=calloc(9,sizeof(int));
int indice_C=0;
for(int i=0;i<9;++i){
if(M[i][j]!=0){
indice_C=indice_C+1;

C[indice_C]=M[i][j];
}
}
// C[0]=indice_C; 
return C;
}


void remplir_case( int **M,int i,int j,int valeur){
M[i][j]=valeur;
}


int *complementaire( int *L,int taille){
int M[9]={1,2,3,4,5,6,7,8,9};
for (int i=0; i<taille; ++i){   // on met à 0 les valeurs communes de L avec la listes {1,...,9}
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

int taille( int* L){
int k=0;
for(int i=0;i<9;++i){
if(L[i]!=0){
k=k+1;
}
}
return k;
}

void afficher_liste(int* L,int taille){
for (int i=0;i<taille;++i){
printf("%d \n ",L[i]);
}
}



int main(){
int *L=calloc(9,sizeof(int));
L[0]=1;
int* comple=complementaire(L,taille(L));
int taille_comple= taille( comple);

afficher_liste(comple,taille_comple);
}














