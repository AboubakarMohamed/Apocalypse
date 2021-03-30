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


int LARGEUR_ECRAN=1000, HAUTEUR_ECRAN=480;
int main ( int argc, char* argv[] )

{
    Minimap m;
    int continuer=1,tempsDebut=0;
    int dimension=0;
    char temps[]="";

    SDL_Event event;
    SDL_Init(SDL_INIT_VIDEO);
TTF_Init();

    SDL_Surface* ecran=NULL, *background_jeu=NULL, *background_joueur=NULL;
    SDL_Rect posJoueur,posImg_Jeu;

    ecran=SDL_SetVideoMode(LARGEUR_ECRAN, HAUTEUR_ECRAN,32, SDL_HWSURFACE| SDL_DOUBLEBUF | SDL_RESIZABLE) ;
    SDL_WM_SetCaption("Skawel",NULL);

    background_jeu=IMG_Load("background.bmp");
    posImg_Jeu.x=0;
    posImg_Jeu.y=0;

    background_joueur=IMG_Load("rouge.bmp");
    posJoueur.x=0;
    posJoueur.y=(ecran->h)-100;


    initmap(&m);

    SDL_BlitSurface(background_jeu,NULL,ecran,&posImg_Jeu);
    SDL_BlitSurface(background_joueur,NULL,ecran,&posJoueur);
    afficherminimap(m,ecran);

    tempsDebut=SDL_GetTicks();
affichertemps(&tempsDebut);
SDL_Flip(ecran);

    while(continuer)
    {
        if(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
            case SDL_QUIT:
                continuer=0;
                break;

            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    tempsDebut=SDL_GetTicks();
                case SDLK_RIGHT:
                    posJoueur.x+=10;
                    m.pos_bonhoe=MAJMinimap(posJoueur,dimension);
                    afficherminimap(m,ecran);
                    break;

                case SDLK_LEFT:
                    posJoueur.x-=10;
                    m.pos_bonhoe=MAJMinimap(posJoueur,dimension);
                    afficherminimap(m,ecran);
                    break;
                }
                break;
            }
        }

        affichertemps(&tempsDebut);
SDL_Flip(ecran);
SDL_Delay(6000);
    }
    Liberer(&m);
    SDL_FreeSurface(background_joueur);
    SDL_FreeSurface(texteTemps);
    SDL_FreeSurface(background_jeu);
    SDL_Quit();
    return 0;
}

