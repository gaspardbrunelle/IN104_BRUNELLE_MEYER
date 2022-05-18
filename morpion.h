#ifndef __MORPION_H__
#define __MORPION_H__


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


// fonction

void remplir_grille( int grille[3][3]);
void afficher_grille( int grille[3][3]);
void placer_chiffre(int grille[3][3],int ligne,int colonne,int joueur );
void chiffre_alea(int grille[3][3]);
bool joueur_gagne( int grille[3][3],int joueur);
bool plein( int grille[3][3]);
int demande_ligne();
int demande_colonne();
void m_morpion();


#endif



