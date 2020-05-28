#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"
#include "colp.h"
#include "dps.h"

int main()
{
SDL_Surface *screen;
//SDL_Surface *image2;
int X,Y,W,H;
int x,y,w,h;
int TT;
perso p;
bk b;
SDL_Surface *texte = NULL;
SDL_Rect position;


SDL_Event event;
SDL_Color col;
int d,click; int i;
TTF_Init();
TTF_Font *police=NULL;
SDL_Color couleurNoire ={0,255,0};
int t=1;
char pause;
if(SDL_Init(SDL_INIT_VIDEO)!=0){
printf("Unable to initialize SDL:%s\n",SDL_GetError());
return 1;
}
screen=SDL_SetVideoMode(1600,400,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
if(screen == NULL){
printf("Unable to set video mode: %s\n",SDL_GetError());
return 1;
}
b.background = SDL_LoadBMP("33.bmp");
//image2 = IMG_Load("11.bmp");
if(b.background==NULL){
printf("Unable to load bitmap: %s\n",SDL_GetError());
return 1;
}
police = TTF_OpenFont("pacifico.ttf",65);
texte = TTF_RenderText_Blended(police,"bonbon!",couleurNoire);
b.positionecran.x = 0;
b.positionecran.y = 0;
X=850;
Y=150;
W = 72;
H= 144;
p.det = IMG_Load("22.png");
SDL_SetColorKey(p.det,SDL_SRCCOLORKEY,SDL_MapRGB(p.det->format,255,255,255));
SDL_EnableKeyRepeat(10,10);
while(t==1)
{
SDL_WaitEvent(&event);
switch(event.type)
{case SDL_QUIT:
t=0;
break;
case SDL_MOUSEBUTTONUP:
if(X!=event.button.x)
{
click=event.button.x;
p=deplacementsourie(p,&X,b,click,screen);
}
break;
case SDL_KEYDOWN:
switch (event.key.keysym.sym)
{
case SDLK_ESCAPE:
t=0;
SDL_ShowCursor(SDL_DISABLE);
break;
case SDLK_UP:
{
Y--;}
break;
case SDLK_DOWN:
{
Y++;}
break;
case SDLK_RIGHT:
{
X++;}
break;
case SDLK_LEFT:
X--;
break;
}
break;
}

p.pos[1].x=X;
p.pos[1].y=Y;
p.pos[2].x=X+(W/2);
p.pos[2].y=Y;
p.pos[3].x=X+W;
p.pos[3].y=Y;
p.pos[4].x=X;
p.pos[4].y=Y+(H/2);
p.pos[5].x=X;
p.pos[5].y=Y+H;
p.pos[6].x=X+(W/2);
p.pos[6].y=Y+H;
p.pos[7].x=X+W;
p.pos[7].y=Y+H;
p.pos[8].x=X+W;
p.pos[8].y=Y+(H/2);

SDL_BlitSurface(b.background,NULL,screen, &b.positionecran);
//SDL_BlitSurface(image2,NULL,screen, &positionecran);
SDL_BlitSurface(p.det,NULL,screen, &p.pos[1]);
SDL_Flip(screen);
TT=colision_perfectp(p,b.background);
if(TT==1)
{
  //return 1; //ak7el
position.x=100;
position.y=100;
SDL_BlitSurface(texte,NULL,screen,&position);
SDL_Flip(screen);
}
}
TTF_CloseFont(police);
TTF_Quit();
SDL_FreeSurface(b.background);
SDL_FreeSurface(p.det);
SDL_Quit();
return 0;
}
