#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "multijoueur.h"
#include "scrolling.h"
#include "min2.h"
mi minimappre(perso p1,mi m2)
{
m2.posmini.x=550+(p1.posjoueur.x/20);
return m2;
}
mi minimapdeu(perso p2,mi m3)
{
m3.posmini.x=550+(p2.posjoueur.x/20);
return m3;
}
void affichemap(SDL_Surface * screen,ma m1,mi m2,mi m3)
{m1.map = IMG_Load("Fichier 1.png");
m2.mini = IMG_Load("Fichier 2.png");
m3.mini = IMG_Load("Fichier 2.png");
SDL_BlitSurface(m1.map,NULL,screen, &m1.posmap);
SDL_BlitSurface(m2.mini,NULL,screen, &m2.posmini);
SDL_BlitSurface(m3.mini,NULL,screen, &m3.posmini);
}
void partagepre(SDL_Surface * screen)
{
Objet *back1;
perso *p1;
SDL_Event event;
back1->img=SDL_CreateRGBSurface(SDL_HWSURFACE,800,400,32,0,0,0,0);
back1->img= IMG_Load("back.png");
back1->pos.x=0;
back1->pos.y=0;
SDL_BlitSurface(back1->img, NULL, screen, &(back1->pos));
SDL_BlitSurface(p1->sprite,&p1->posanimation,screen,&p1->posjoueur);
}
void partagedeu(SDL_Surface * screen)
{
Objet *back2;
SDL_Event event;
perso *p2;
back2->img=SDL_CreateRGBSurface(SDL_HWSURFACE,800,400,32,0,0,0,0);
back2->img= IMG_Load("back.png");
back2->pos.x=0;
back2->pos.y=400;
SDL_BlitSurface(back2->img, NULL, screen, &(back2->pos));
SDL_BlitSurface(p2->sprite,&p2->posanimation,screen,&p2->posjoueur);
}

void init_perso(perso *p1,perso *p2)
{
p1->posanimation.x=0;
p1->posanimation.y=0;
p1->posanimation.w=100;
p1->posanimation.h=100;
p1->posjoueur.x=0;
p1->posjoueur.y=250;
p1->posjoueur.w=100;
p1->posjoueur.h=100;
p2->posanimation.x=0;
p2->posanimation.y=0;
p2->posanimation.w=100;
p2->posanimation.h=100;
p2->posjoueur.x=0;
p2->posjoueur.y=650;
p2->posjoueur.w=100;
p2->posjoueur.h=100;
}
int charger_sprite(perso *p1,perso *p2)
{
p1->sprite=IMG_Load("99.png");
p2->sprite=IMG_Load("99.png");
if((p1->sprite==0)&&(p2->sprite==0))
{
printf("unable to load perso:%s\n",SDL_GetError());
return -1 ;
}
return 0;
}
void animate_personnagepre(perso *p1)
{
p1->posanimation.x +=100;
if (p1->posanimation.x==400)
p1->posanimation.x=0;
SDL_Delay(30);
}
void animate_personnagedeu(perso *p2)
{
p2->posanimation.x +=100;
if (p2->posanimation.x==400)
p2->posanimation.x=0;
SDL_Delay(30);
}
void affiche_persopre(perso *p1,SDL_Surface *screen)
{
SDL_BlitSurface(p1->sprite,&p1->posanimation,screen,&p1->posjoueur);
SDL_Flip(screen);
}
void affiche_persodeu(perso *p2,SDL_Surface *screen)
{
SDL_BlitSurface(p2->sprite,&p2->posanimation,screen,&p2->posjoueur);
SDL_Flip(screen);
}
void gestion_evenement(SDL_Event event,perso *p1,perso *p2,SDL_Surface * screen)
{
int keep=1;
int x;
mi m2,m3;
ma m1;
Objet *back1,*back2;
m1.posmap.x=540;
m1.posmap.y=360;
m2.posmini.x=550;
m2.posmini.y=360;
m3.posmini.x=550;
m3.posmini.y=375;
init_perso(p1,p2);
x=charger_sprite(p1,p2);
while(keep==1)
{
partagepre(screen);
partagedeu(screen);
m2=minimappre((*p1),m2);
m3=minimapdeu((*p2),m3);
affichemap( screen,m1, m2,m3);
affiche_persopre(p1,screen);
affiche_persodeu(p2,screen);
SDL_EnableKeyRepeat(10,10);
SDL_Flip(screen);
SDL_PollEvent(&event);
switch(event.type)
{
case SDL_QUIT:
keep=0;
break;
case SDL_KEYUP:
affiche_persopre(p1,screen);
affiche_persodeu(p2,screen);
break;
case SDL_KEYDOWN:
if(event.key.keysym.sym==SDLK_LEFT)
{p1->posjoueur.x-=5;
p1->posanimation.y=100;
animate_personnagepre(p1);
}
if(event.key.keysym.sym==SDLK_q)
{p2->posjoueur.x-=5;
p2->posanimation.y=100;
animate_personnagedeu(p2);
}
if((event.key.keysym.sym==SDLK_RIGHT))
{p1->posanimation.y=200;
animate_personnagepre(p1);
{p1->posjoueur.x+=5;
}
}
if(event.key.keysym.sym==SDLK_d)
{ p2->posjoueur.x+=5;
p2->posanimation.y=200;
animate_personnagedeu(p2);
}
if(event.key.keysym.sym==SDLK_UP)
{p1->posjoueur.y-=5;
p1->posanimation.y=0;
animate_personnagepre(p1);

}
if(event.key.keysym.sym==SDLK_z)
{
 p2->posanimation.y=0;
 animate_personnagedeu(p2);
}
if(event.key.keysym.sym==SDLK_DOWN)
{  p1->posjoueur.y+=5;
p1->posanimation.y=300;
  animate_personnagepre(p1);
}
if(event.key.keysym.sym==SDLK_s)
 {  p2->posanimation.y=300;
    animate_personnagedeu(p2);
}
break;
}
}
}


