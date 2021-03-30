#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_getenv.h>
#include <SDL/SDL_mixer.h>
#include "minimap.h"
#include <string.h>
#include <math.h>




void initmap(Minimap *m)
{
    m->pos_mini.x=100;
    m->pos_mini.y=0;

    m->pos_bonhoe.x=100;
    m->pos_bonhoe.y=76;/*(m->pos_mini.h)-(m->pos_bonhoe.h)*/

    m->background_minimap=IMG_Load("minibackground.bmp");
    m->bonhomme=IMG_Load("minirouge.bmp");
}

SDL_Rect MAJMinimap( SDL_Rect posJoueur, int redimensionnement)
{
SDL_Surface* ecran=NULL;
    redimensionnement=20;
    SDL_Rect pos_bonhoe,camera,posJoueurABS;

    camera.x=(posJoueur.x);
    camera.y=(ecran->h)-(posJoueur.h)+5;

    if(SDLK_LEFT)
        camera.x--;
    if(SDLK_RIGHT)
        camera.x++;
    if(SDLK_UP)
        camera.y--;
    if(SDLK_DOWN)
        camera.y++;

    posJoueurABS.x=posJoueur.x+camera.x;
    posJoueurABS.y=posJoueur.y+camera.y;

    pos_bonhoe.x=(posJoueurABS.x)*(redimensionnement/100);
    pos_bonhoe.y=(posJoueurABS.y)*(redimensionnement/100);

    return pos_bonhoe;
}

void afficherminimap(Minimap m,SDL_Surface *ecran)
{
    SDL_BlitSurface(m.background_minimap,NULL,ecran,&(m.pos_mini));
    SDL_BlitSurface(m.bonhomme,NULL,ecran,&(m.pos_bonhoe));

}

void Liberer(Minimap*m)
{
    SDL_FreeSurface(m->background_minimap);
    SDL_FreeSurface(m->bonhomme);
}

void affichertemps(int* tempsDebut)
{
   int tempsActuel=0;
    char temps[]="";

    TTF_Init();
 SDL_Surface* texteTemps=NULL, *ecran=NULL;
 SDL_Rect posTexte;

    //Chargement police
 TTF_Font* police=NULL;
 police=TTF_OpenFont("police.ttf",32);
 SDL_Color couleurNoir={0,0,0};

    //Initialisation de la position du texte
 posTexte.x=0;
 posTexte.y=100;

tempsActuel=SDL_GetTicks();
tempsActuel=(tempsActuel/1000)-((*tempsDebut)/1000);
sprintf(temps,"%d",tempsActuel);
texteTemps=TTF_RenderText_Blended(police,temps,couleurNoir);
SDL_BlitSurface(texteTemps,NULL,ecran,&posTexte);

}

