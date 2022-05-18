#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "pacman.h"



// #define height 1
// #define NR_GHOSTS 20

char area[][60]=
{
   { "############################################################" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#        # # # # #          #             # # # # # #      #" },
   { "#        #       #         # #            #                #" },
   { "#        #       #        #   #           #                #" },
   { "#        # # # # #       #     #          #                #" },
   { "#        #              # # # # #         #                #" },
   { "#        #             #         #        #                #" },
   { "#        #            #           #       #                #" },
   { "#        #           #             #      #                #" },
   { "#        #          #               #     # # # # # #      #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#        ##        ##           #          ##        #     #" },
   { "#        # #      # #          # #         # #       #     #" },
   { "#        #  #    #  #         #   #        #  #      #     #" },
   { "#        #    # #   #        #     #       #   #     #     #" },
   { "#        #     #    #       # # # # #      #    #    #     #" },
   { "#        #          #      #         #     #     #   #     #" },
   { "#        #          #     #           #    #      #  #     #" },
   { "#        #          #    #             #   #       # #     #" },
   { "#        #          #   #               #  #        ##     #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "############################################################" }
};




             
//struct Ghost   * empty_ghost_struct(){
//	struct Ghost * liste_ghost = calloc(NR_GHOSTS,sizeof( struct Ghost));
//	return liste_ghost;

//}           
               
void initiate_pacman(struct pacman* pc,char a[][60]){
	struct coordinates coord={1,
        	                  1,
        	                  };
             pc->pacman_coord=coord;
             pc->nx= 0;
             pc->ny= 0;
             pc->lives= 1;
             pc->food_collected=0;
             pc->chasing=true;      
             
             a[1][1]='P';       
}	

void put_food( char a[][60]){
	for(int i=0;i<30;++i){
		for(int j=0;j<60;++j){
			if(a[i][j]==' '){
				a[i][j]='.';
			
			}
					
		}
	}
}			



struct coordinates coord_possible_ghosts2(char a[][60],int l[NR_GHOSTS],int c[NR_GHOSTS],int i){ // position du ghosts actuel dont on cherche sa coordoonées
	int ligne;
	int colonne;
	
	bool position_ok=false;
	// attention au barriere
	while(!position_ok){ // tant que c'est pas ok
	
		ligne=rand()%30;
		colonne=rand()%60;
		bool b2=true;  // les ghosts ne se touchent pas
		bool b3= !(ligne==1 && colonne==1); // verifie si on est pas sur la position initiale du pacman: b3=pas de probleme
		bool b4 = (a[ligne][colonne] ==' '); // verifie qu'on est bien sur un emplacement vide
		bool b5= !(a[ligne][colonne] =='#'); // plutot ' ' inutile
		
		if(i>0){ // au moins un autre ghosts 
		
			for(int k=0;k<i;++k){
				bool b3= ligne==1 && colonne==1;
				
				if(ligne ==l[k] && colonne == c[k] ){ // verifier ici
		 	    	b2=false; // le ghosts i (0,1 ,...) touche le ghosts k
		   	  	}
			}     
				
			if( b2 && b3 && b4){
				position_ok=true;
			}
		}
		
		else{ // i=0 donc premier ghosts et donc pas de probleme avec les autres
			if( b3 && b4){ // si pas à l'origine et dans une espace vide
				position_ok=true;
			}	
		}	
	}
	struct coordinates coordinate={ ligne,colonne};
	return coordinate; 
			
}
		

             
void initialise_ghost2(char a[][60],struct Ghost all_g[NR_GHOSTS]){
	int ligne[NR_GHOSTS]; // position des ghosts
	int colonne[NR_GHOSTS]; // position des ghosts
	for(int i=0;i<NR_GHOSTS;++i){
		(all_g[i]).chasing=true;
		struct coordinates coord_g=coord_possible_ghosts2(area,ligne,colonne,i);  // on prend la coordonnées de ghost
		(all_g[i]).ghost_coord=coord_g; // on met cette coordonnees dans le ghost
		int l=(coord_g).x;
		int c=(coord_g).y;
		ligne[i]=l;
		colonne[i]=c;
		a[l][c]='F';//?
		
	}	
	 put_food(area);	

}

		
			
void test (char a[][60]){
	if(a[1][1]==' '){
	printf("ok");
	}
}	




void affichage(char a[30][60]){
	system("clear");
	
	for(int i=0;i<30;++i){
		for(int j=0;j<60;++j){
			if(a[i][j]=='F'){ 
				printf("%c",'G');
			}
			else{	
			printf("%c" , a[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n");		
}		


void deplace_ghosts(struct Ghost all_g[NR_GHOSTS],char a[][60]){
	for(int i=0;i<NR_GHOSTS;++i){ // pour chaque ghosts
		struct coordinates ancienne_coord_g= (all_g[i]).ghost_coord;
		
		
		
		int iter=0;
		
		int direction=rand()%2; // si =0: deplacement selon x, si =1: deplacement selon y	
		 int nx_g=rand()%2 +1; // 1-> 1 ; 2-> -1 	
		int ny_g=rand()%2 +1; // 1-> 1 ; 2-> -1  
		
		if( nx_g==2){
			nx_g=-1;
		}
		if( ny_g==2){
			ny_g=-1;
		}	
		
		if (direction==0){ny_g=0;}
		if (direction==1){nx_g=0;}
		
		int new_x_g=(ancienne_coord_g).x+nx_g; // les nouvelles coordonnées du ghosts si tout va bien 
		int new_y_g=(ancienne_coord_g).y+ny_g;
		
		
		
		bool collision_mur = a[new_x_g][new_y_g]== '#';
		if ( !collision_mur){  }
		
		
		while( collision_mur ) // si ça n'a pas larché on recommence
		{
			 int direction=rand()%2; // si =0: deplacement selon x, si =1: deplacement selon y	
			  int nx_g=rand()%2 +1; // 1-> 1 ; 2-> -1 	
			 int ny_g=rand()%2 +1; // 1-> 1 ; 2-> -1  
		
			if( nx_g==2){
				nx_g=-1;
			}
			if( ny_g==2){
				ny_g=-1;
			}	
			
			if (direction==0){ny_g=0;}
			if (direction==1){nx_g=0;}
			
			int new_x_g=(ancienne_coord_g).x+nx_g;
			int new_y_g=(ancienne_coord_g).y+ny_g;
			
			
			 collision_mur = ( a[new_x_g][new_y_g]== '#') ;
			if ( !collision_mur){  }
			
		
		}
		
		// on a ici un bon déplacement
		
		struct coordinates new_coord_g={ new_x_g,new_y_g};
		
		(all_g[i]).ghost_coord= new_coord_g;
		
		
		if(a[ (ancienne_coord_g).x][(ancienne_coord_g).y]=='F'){ // probleme quand on met ca
		
		
		a[ (ancienne_coord_g).x][(ancienne_coord_g).y]='.'; // on remet la food qui etait avec le ghosts
		
		
		}
		
		if(a[new_x_g][new_y_g]=='.'){
		a[new_x_g][new_y_g]='F'; // F pour ghosts  sur une food
		}
		
		
		
	
		
		
	}	

}




void keyboard(struct pacman *pc ,struct Ghost all_g[NR_GHOSTS] )
{
	printf("pressez 1 (monter) ou 2 (aller à gauche) ou 3 (aller en bas) ou 4 (aller à droite): \n  ");
	int c;
	scanf("%d",&c);
	bool b1= ( ((c==1) || (c==2))  || ((c==3) || (c==4))  );
	if(b1)
	{
		if(c==1){ //z
			pc->nx=-1;
			pc->ny=0;
		}
		if(c==2){ //q
			pc->nx=0;
			pc->ny=-1;
		}
		if(c==3){ //s
			pc->nx=1;
			pc->ny=0;
		}
		if(c==4){ //d
			pc->nx=0;
			pc->ny=1;
		}
	}
	else{
		pc->nx=3; // pour detecter qu'il n'ya pas de mouvement
	}
	deplace_ghosts(all_g,area); // probleme
}



bool collision(struct coordinates n_c,char a[][60]){
	bool c=false ;
	
	int x = (n_c).x;
	int y= (n_c).y;
	if(a[x][y]=='#' || a[x][y]=='G'){
		c=true;
	}	
	
	return c;
}
	
       
void moves_pacman(struct pacman *pc,char a[][60]){
	// le cas ou on bouge pas
	if(pc->nx==3){
	// pas de mouvement
	}
	else
	{
	
	struct coordinates ancienne_coord_pc= (pc)->pacman_coord; // on récupere les anciennes coordonnées du pacman avant mis a jour

	if (a[(ancienne_coord_pc).x][(ancienne_coord_pc).y] =='G'){ // si le ghosts n'a pas pris l'ancienne place du pacman, car le ghosts peut prendre la place du pacman en meme temps que le pacman se deplace 
		
	}
	else{
	a[(ancienne_coord_pc).x][(ancienne_coord_pc).y] =' '; // on enleve le pacman de son ancienne position
	}
	int new_x=(ancienne_coord_pc).x + pc->nx; // indice de ligne
	int new_y=(ancienne_coord_pc).y + pc->ny;
	
	struct coordinates nouvelle_coord ={ new_x,new_y}; // on calcule les nouvelles coordoonées
	// on doit tester que le pacman ne rentre pas dans un mur ou dans un ghosts
	bool col= collision(nouvelle_coord, a );
	
	if (col){ // si il y a colision avec le mur ou le ghosts (qui a bouge en meme temps que le pacman)
		pc->lives=pc->lives -1; 
		struct coordinates c={1,1};
		(pc)->pacman_coord=c;
		// on peut afficher ici a sans P
		a[1][1]='P';
	} 
	
	else{ // si pas de colision
		(pc)->pacman_coord=nouvelle_coord;
		if (a[new_x][new_y]='.'){ // si le pacman arrive sur un emplacement food
			(pc)->food_collected=(pc)->food_collected +1; // on rajoute +1 à la reserve de food
		}
		a[new_x][new_y]='P';
		
	}
	
	}
	
}			
		
		
	
void checks_lives(struct pacman* pc,char a[][60])
{
	int lives =pc->lives;
	int food=pc->food_collected;
	if(lives<0){
		printf(" score : %d",food);
	}
	else{
		affichage(area);
	}
}
     
       
      
       
void m_pacman()
{
	srand( time( NULL ) );
	struct Ghost all_gh[NR_GHOSTS];
	struct pacman* pac=malloc(sizeof(struct pacman));
	initialise_ghost2(area,all_gh);
	initiate_pacman(pac,area);
	affichage(area);
	while(pac->lives> -1){
		keyboard(pac ,all_gh );
		moves_pacman(pac,area);
		checks_lives(pac,area);
	}
	
}


                                  
