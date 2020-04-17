#include <SDL/SDL.h>
#include <SDL/SDL_image.h>


typedef struct 
{
  SDL_Surface *img ;
  SDL_Rect pos;  
}Objet;


void init (SDL_Surface *screen,Objet *objet1,Objet *objet2) ;
void deplacement_objet(SDL_Event event,SDL_Surface *screen,Objet *objet1,Objet *objet2) ;
void liberate_memory (Objet *objet1,Objet *objet2) ;