#include <stdio.h>
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "colision.h"

int X;

int deplacement_sourie(perso p,int click)
{
X=p.pos[1].x;
if(p.pos[1].x<click)
{
do{
X++;
affich();
}while(X!=click);
}
if(p.pos[1].x>click)
{
do{
X--;
affich();
}while(X!=click);
}
return X;
}
