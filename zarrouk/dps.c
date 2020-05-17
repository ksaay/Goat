#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"
#include "colp.h"
#include "dps.h"


perso deplacementsourie(perso p,int *X,bk b,int click,SDL_Surface *screen)
{
(*X)=p.pos[1].x;
if(p.pos[1].x<click)
{
do{
(*X)++;
p.pos[1].x++;
SDL_BlitSurface(b.background,NULL,screen, &b.positionecran);
SDL_BlitSurface(p.det,NULL,screen, &p.pos[1]);
SDL_Flip(screen);
}while((*X)!=click);
}
if(p.pos[1].x>click)
{
do{
(*X)--;
p.pos[1].x--;
SDL_BlitSurface(b.background,NULL,screen, &b.positionecran);
SDL_BlitSurface(p.det,NULL,screen, &p.pos[1]);
SDL_Flip(screen);
}while((*X)!=click);
}
return p;
}
