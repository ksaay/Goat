#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "SDL/SDL_ttf.h"
#include "min2.h"
#include "mini.h"


perso jump(perso p,bk b,ma m1,mi m2,int *d,SDL_Surface *screen,int *X,int *Y)
{
if((*d)==1){
do
{
(*Y)--;
p.pos[1].y--;
(*X)++;
p.pos[1].x++;
SDL_BlitSurface(b.background,NULL,screen, &b.positionecran);
SDL_BlitSurface(p.det,NULL,screen, &p.pos[1]);
SDL_BlitSurface(m1.map,NULL,screen, &m1.posmap);
SDL_BlitSurface(m2.mini,NULL,screen, &m2.posmini);
SDL_Flip(screen);
}while(p.pos[1].y>130);
do{(*Y)++;
p.pos[1].y++;
(*X)++;
p.pos[1].x++;
SDL_BlitSurface(b.background,NULL,screen, &b.positionecran);
SDL_BlitSurface(p.det,NULL,screen, &p.pos[1]);
SDL_BlitSurface(m1.map,NULL,screen, &m1.posmap);
SDL_BlitSurface(m2.mini,NULL,screen, &m2.posmini);
SDL_Flip(screen);
}while(p.pos[1].y<150);}

if((*d)==2){
do
{
(*Y)--;
p.pos[1].y--;
(*X)--;
p.pos[1].x--;
SDL_BlitSurface(b.background,NULL,screen, &b.positionecran);
SDL_BlitSurface(p.det,NULL,screen, &p.pos[1]);
SDL_BlitSurface(m1.map,NULL,screen, &m1.posmap);
SDL_BlitSurface(m2.mini,NULL,screen, &m2.posmini);
SDL_Flip(screen);
}while(p.pos[1].y>130);
do{(*Y)++;
p.pos[1].y++;
(*X)--;
p.pos[1].x--;
SDL_BlitSurface(b.background,NULL,screen, &b.positionecran);
SDL_BlitSurface(p.det,NULL,screen, &p.pos[1]);
SDL_BlitSurface(m1.map,NULL,screen, &m1.posmap);
SDL_BlitSurface(m2.mini,NULL,screen, &m2.posmini);
SDL_Flip(screen);
}while(p.pos[1].y<150);}

if((*d)==0){
do
{
(*Y)--;
p.pos[1].y--;
SDL_BlitSurface(b.background,NULL,screen, &b.positionecran);
SDL_BlitSurface(p.det,NULL,screen, &p.pos[1]);
SDL_BlitSurface(m1.map,NULL,screen, &m1.posmap);
SDL_BlitSurface(m2.mini,NULL,screen, &m2.posmini);
SDL_Flip(screen);
}while(p.pos[1].y>130);
do{(*Y)++;
p.pos[1].y++;
SDL_BlitSurface(b.background,NULL,screen, &b.positionecran);
SDL_BlitSurface(p.det,NULL,screen, &p.pos[1]);
SDL_BlitSurface(m1.map,NULL,screen, &m1.posmap);
SDL_BlitSurface(m2.mini,NULL,screen, &m2.posmini);
SDL_Flip(screen);
}while(p.pos[1].y<150);}
(*d)=0;
return p;
}
