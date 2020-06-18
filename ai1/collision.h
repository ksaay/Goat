#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

typedef struct 
{
  SDL_Surface *img ;
  SDL_Rect pos;  
  int w;
  int h;
  int xg;
  int xd;
}Objet;


void init (Objet *objet1,Objet *objet2) ;
void setup (SDL_Surface *screen,Objet *objet1,Objet *objet2) ;
int verif_collision ( Objet *objet1,Objet *objet2 ) ;
void deplacement_objet(Objet *objet,int *running) ;
void update (SDL_Surface *screen,Objet *objet1,Objet *objet2) ;
void liberate_memory (Objet *objet1,Objet *objet2) ;
int distance (Objet *objet1,Objet *objet2);
