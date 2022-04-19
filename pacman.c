#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



#define height 1
#define nb_ghost 1


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
                
struct ghost { struct coordinates ghost_coord;
               int nx;
               int ny;
               bool chasing;
             };
             
struct ghost   * empty_ghost_struct(){
	struct ghost * liste_ghost = calloc(nb_ghost,sizeof( struct ghost));
	return liste_ghost;

}           
               
struct pacman initiate_pacman(){
	struct coordinates coord={0;
        	                  0;
        	                  };
                          
	struct pacman pc= { coord;
        	           0;
        	           0;
        	           100;
        	           0;
        	           false;
        	          };
                  
}
                              
int main(){
struct ghost* l_g=empty_ghost_struct();


}                                  
