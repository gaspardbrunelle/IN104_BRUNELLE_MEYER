/* Gaspard Brunelle */

#include <stdio.h>
#include <stdlib.h>

struct intervalle { double inf;
                    double sup;
                  };
                  
void affichage ( struct intervalle I){ printf(" [ %f, %f] \n ",I.inf,I.sup);}


/*  //Q3:
int main(){
struct intervalle I1={-1,9}; 
struct intervalle I2={-3,5};

affichage(I1);
affichage(I2);
}                 
*/                      

struct intervalle saisie_intervalle(){double a;
                                      double b;
                                      
                                      printf(" borne inf?");
                                     
                                      scanf( "%lf",&a);
                                      printf(" borne sup?");
                                     
                                      scanf( "%lf",&b);
                                      struct intervalle I={a,b};
                                      return I;
                                      }
                                    


struct intervalle intersection(struct intervalle I1,struct intervalle I2){ double a ;
                                                                           double b ;
                                                                           struct intervalle* I11=&I1;
                                                                           struct intervalle* I22=&I2;
                                                                           if (I11->inf>= I22->inf) { a=I11->inf;}
                                                                           else {a=I22->inf;};
                                                                           
                                                                           if (I11->sup <= I22->sup) { b=I11->sup;}
                                                                           else {b=I22->sup;};
                                                                           
                                                                           
                                                                           struct intervalle I3={a,b};
                                                                           return I3;
 
                                                                           }
                                                                           
 /*                                                                          
 int main(){struct intervalle I1={-1,9}; 
struct intervalle I2={-3,5};
  affichage(intersection(I1,I2));}                                                                            
*/                                                                        
                                                                        
struct intervalle* saisie_tableau(int n){
struct intervalle* tableau = malloc(1024*8182);
for (int i=1; i<=n;++i){printf("saisie intervalle :");   // le tableau commence a l'indice 1
                         tableau[i]=saisie_intervalle();
                         
                         }
                        return tableau;
                        }
 /*                       
  int main(){      struct intervalle* a= saisie_tableau(2); printf("%p",&a);   // exemple 
  struct intervalle I1=a[1];
  printf("\n");
  printf("%f",I1.inf);}
*/



struct intervalle intersection_tableau(struct intervalle* tableau, int n){
                                                                          struct intervalle I0= tableau[1];
                                                                          for (int i=1; i<=n-1; ++i) {
                                                                                                   I0=intersection(I0,tableau[i+1]);
                                                                                                   } 

                                                                          return I0;
                                                                          }
 /*
 // Q7:                                                                         
int main(){
struct intervalle I1= intersection_tableau( saisie_tableau(3),3);
affichage(I1);
}       
saisie intervalle 1=i: borne inf?1
 borne sup?9
saisie intervalle 1=i: borne inf?1
 borne sup?9
saisie intervalle 1=i: borne inf?2
 borne sup?9
 [ 2.000000, 9.000000]                                                                    
*/

void affichage_tableau_inverse(struct intervalle* tableau, int n){
                                                                   for( int i=n; i>=1;--i){
                                                                                            affichage(tableau[i]);
                                                                                            }
/*                                                                 }
int main(){
struct intervalle* tableau= saisie_tableau(3);
affichage_tableau_inverse(tableau,3);
} 

saisie intervalle : borne inf?1
 borne sup?2
saisie intervalle : borne inf?3
 borne sup?4
saisie intervalle : borne inf?5
 borne sup?6
 [ 5.000000, 6.000000] 
  [ 3.000000, 4.000000] 
  [ 1.000000, 2.000000] 

 int main(){ free(tableau)
 }                                                                                          
*/ 
                                                                        
                                                                        
