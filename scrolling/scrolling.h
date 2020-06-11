#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#define mapw 6838 
#define maph 613

#define xwood 300
#define ywood 360

#define xboat 50
#define yboat 400

#define xd 100
#define yd 360

#define wd 72
#define hd 144

#define xb 2293
#define yb 316

#define wb 559
#define hb 128

typedef struct 
{
  SDL_Surface *img ;
  SDL_Rect pos; 
  int w1;
  int h1;
} Objet;
void partagepre(SDL_Surface *screen);
void partagedeu(SDL_Surface *screen);
void initialiser (Objet *map ,Objet *d );
void setup (SDL_Surface *screen, Objet *map , Objet *d);
void scrolling_droitpre ( Objet *back1);
void scrolling_droitdeu ( Objet *back2);
void scrolling_gauche (SDL_Surface*screen , Objet *back1);
void evenement (SDL_Surface *screen ,Objet *map,int *running , Objet *d);
int check_collision(SDL_Rect pos,SDL_Rect pos1);
void free_memory (Objet *map, Objet *d);
