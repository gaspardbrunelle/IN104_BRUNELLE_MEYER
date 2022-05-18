#ifndef __PACMAN_H__
#define __PACMAN_H__


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


#define height 1
#define NR_GHOSTS 20

struct coordinates { int x;
                     int y;
                     };
                     
struct pacman { struct coordinates  pacman_coord;
                int nx;
                int ny;
                int lives;
                int food_collected;
                bool chasing;
                };
                
struct Ghost { struct coordinates ghost_coord;
               int nx;
               int ny;
               bool chasing;
             };
             


// fonction


void initiate_pacman(struct pacman* pc,char a[][60]);
void put_food( char a[][60]);
struct coordinates coord_possible_ghosts2(char a[][60],int l[NR_GHOSTS],int c[NR_GHOSTS],int i);
void initialise_ghost2(char a[][60],struct Ghost all_g[NR_GHOSTS]);
void affichage(char a[30][60]);
void deplace_ghosts(struct Ghost all_g[NR_GHOSTS],char a[][60]);
void keyboard(struct pacman *pc ,struct Ghost all_g[NR_GHOSTS] );
bool collision(struct coordinates n_c,char a[][60]);
void moves_pacman(struct pacman *pc,char a[][60]);
void checks_lives(struct pacman* pc,char a[][60]);

void m_pacman();




#endif
