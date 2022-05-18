#ifndef __SUDOKU_H__
#define __SUDOKU_H__


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int* convert_gb(int x [2]);
int* convert_bg(int x [2]);
int taille( int* L);
bool nombre_is_correct(int nombre);
bool ligne_is_correct(int ligne, int **M);
bool colonne_is_correct(int colonne,int **M);
bool bloc_is_correct(int n_bloc,int **M);
bool matrice_is_correct(int **M);
bool point_is_correct(int i, int j,int **M, int s[9][9]);
int *complementaire( int *L,int taille);
int ** creer_bloc(int taille);
int *intersection(int* L1, int* L2,int taille_L1,int taille_L2);
int *Ligne_Libre(int i, int**M);
int *Colonne_Libre(int j, int **M);
void remplir_case( int **M,int i,int j,int valeur); //i
void afficher_liste(int* L,int taille); // i
int *liste_alea1();
void afficherliste(int entier[9]); //i
void remplir_bloc_diagonale(int **M,int n_bloc);
void print_ligne();
void afficher_matrice(int **M);
void afficher_matrice2(int matrice[9][9] ); //i
int *Bloc_Libre(int n_bloc,int **M);
int trouver_chiffre(int **M,int n_bloc,int k);
bool bloc_rempli(int n_bloc,int **M);
bool ligne_rempli(int i,int **M);
void remplir_ligne(int i,int **M);
void bloc_a_zero(int n_bloc,int**M);
void remplir_bloc_non_diagonale(int n_bloc,int **M);
bool matrice_rempli(int **M);
void remplir_matrice(int **M);
void enlever_case(int nombre,int **M);
int ** generer();
int* trouver_erreur(int **M);
void afficher_erreur(int *erreur);
void jouer(int **M);
void copie(int M_cible[][9],int **M_acopier);
void m_sudoku();


#endif


























