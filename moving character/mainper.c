#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "deppers.h"

#define width 1600
#define height 400

int main()
{
  SDL_Surface *screen=NULL ;
  SDL_Event event;
  int running=1 ;

  Objet objet1,objet2 ;

   SDL_Init(SDL_INIT_VIDEO);

    screen = SDL_SetVideoMode(width, height, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
    init (screen,&objet1,&objet2);
   
    
    SDL_EnableKeyRepeat(10, 10);

    while(running==1){
     deplacement_objet(event,screen,&objet1,&objet2) ;
     

    }
    
    liberate_memory (&objet1,&objet2) ;




    return EXIT_SUCCESS;
}



