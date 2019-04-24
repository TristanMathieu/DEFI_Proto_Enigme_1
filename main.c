#include <stdio.h>
#include <stdlib.h>
#include <SDL2\SDL.h>
#include <time.h>

void delay(unsigned int frameLimit);

int main(int argc, char** argv)
{
    printf("Lancement...\n");

    //Initialisation de la SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        //Message d'erreur
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        return -1;

    } else {
        printf("Prototype enigme 1 : Les couleurs\nL'objectif est d'utiliser chaques couleurs 2 fois, et que chaques case soit identique en haut et en bas.\n");
        //Traitement
        //Init. Variables
        Uint8 *state = SDL_GetKeyboardState(NULL);
        int dieudonne;
        int monstre;

        //Pour les 60 fps
        unsigned int frameLimit = SDL_GetTicks() + 16;

        //Création de la page
        SDL_Window *pWindow = SDL_CreateWindow("Prototype enigme 1", 100, 100, 640, 480, 0);
        SDL_Renderer *renderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);

        SDL_Rect h1;
            h1.x=50;
            h1.y=50;
            h1.w=50;
            h1.h=50;

        SDL_Rect h2;
            h2.x=150;
            h2.y=50;
            h2.w=50;
            h2.h=50;

        SDL_Rect h3;
            h3.x=250;
            h3.y=50;
            h3.w=50;
            h3.h=50;


        SDL_Rect b1;
            b1.x=50;
            b1.y=250;
            b1.w=50;
            b1.h=50;

        SDL_Rect b2;
            b2.x=150;
            b2.y=250;
            b2.w=50;
            b2.h=50;

        SDL_Rect b3;
            b3.x=250;
            b3.y=250;
            b3.w=50;
            b3.h=50;

        //SDL_SetRenderDrawColor( renderer, 100, 100, 100, 255 );
        //SDL_RenderFillRect(renderer, &h1);
        int couleur_h1=1;
        int couleur_h3=1;
        int couleur_b2=1;
        int couleur_b3=1;

        SDL_RenderPresent(renderer);



        //Si la page s'est bien créée
        if( pWindow )
        {
            //Init. Var.
            int cont = 1;
            SDL_Event event;

            while(cont !=0){


                while (SDL_PollEvent(&event))
                {
                    switch(event.type)
                    {
                        //case on click sur la croix en haut a droite
                        case SDL_QUIT:
                            printf("\n\nProcedure de fermeture lancee.");
                            cont = 0;
                            break;

                        case SDL_MOUSEBUTTONDOWN:
                            if (SDL_GetMouseState(&dieudonne, &monstre) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
                                if ((dieudonne>h1.x) & (monstre>h1.y) & (dieudonne<(h1.x+h1.w)) & (monstre<(h1.y+h1.h))){
                                    couleur_h1++;
                                    if (couleur_h1==4){
                                        couleur_h1=1;
                                    }
                                }
                                if ((dieudonne>h3.x) & (monstre>h3.y) & (dieudonne<(h3.x+h3.w)) & (monstre<(h3.y+h3.h))){
                                    couleur_h3++;
                                    if (couleur_h3==4){
                                        couleur_h3=1;
                                    }
                                }
                                if ((dieudonne>b2.x) & (monstre>b2.y) & (dieudonne<(b2.x+b2.w)) & (monstre<(b2.y+b2.h))){
                                    couleur_b2++;
                                    if (couleur_b2==4){
                                        couleur_b2=1;
                                    }
                                }
                                if ((dieudonne>b3.x) & (monstre>b3.y) & (dieudonne<(b3.x+b3.w)) & (monstre<(b3.y+b3.h))){
                                    couleur_b3++;
                                    if (couleur_b3==4){
                                        couleur_b3=1;
                                    }
                                }
                            }
                            break;


                        case SDL_KEYDOWN:
                            if (state[SDL_SCANCODE_ESCAPE]) {
                                printf("\n\nProcedure de fermeture lancee.");
                                cont = 0;
                            }


                            break;

                        default:
                            break;

                    }

                // Gestion des 60 fps (1000ms/60 = 16.6 -> 16
                delay(frameLimit);
                frameLimit = SDL_GetTicks() + 16;


                //Les FPS
                SDL_RenderClear(renderer);
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderClear(renderer);
                SDL_RenderPresent(renderer);


                switch(couleur_h1) {
                case 1 :
                    SDL_SetRenderDrawColor(renderer, 100, 100, 0, 255);
                    break;
                case 2 :
                    SDL_SetRenderDrawColor(renderer, 160, 100, 0, 255);
                    break;
                case 3 :
                    SDL_SetRenderDrawColor(renderer, 220, 100, 0, 255);
                    break;
                }
                SDL_RenderFillRect(renderer, &h1);

                SDL_SetRenderDrawColor(renderer, 160, 100, 0, 255);
                SDL_RenderFillRect(renderer, &h2);

                switch(couleur_h3) {
                case 1 :
                    SDL_SetRenderDrawColor(renderer, 100, 100, 0, 255);
                    break;
                case 2 :
                    SDL_SetRenderDrawColor(renderer, 160, 100, 0, 255);
                    break;
                case 3 :
                    SDL_SetRenderDrawColor(renderer, 220, 100, 0, 255);
                    break;
                }
                SDL_RenderFillRect(renderer, &h3);

                SDL_SetRenderDrawColor(renderer, 100, 100, 0, 255);
                SDL_RenderFillRect(renderer, &b1);

                switch(couleur_b2) {
                case 1 :
                    SDL_SetRenderDrawColor(renderer, 100, 100, 0, 255);
                    break;
                case 2 :
                    SDL_SetRenderDrawColor(renderer, 160, 100, 0, 255);
                    break;
                case 3 :
                    SDL_SetRenderDrawColor(renderer, 220, 100, 0, 255);
                    break;
                }
                SDL_RenderFillRect(renderer, &b2);

                switch(couleur_b3) {
                case 1 :
                    SDL_SetRenderDrawColor(renderer, 100, 100, 0, 255);
                    break;
                case 2 :
                    SDL_SetRenderDrawColor(renderer, 160, 100, 0, 255);
                    break;
                case 3 :
                    SDL_SetRenderDrawColor(renderer, 220, 100, 0, 255);
                    break;
                }
                SDL_RenderFillRect(renderer, &b3);


                SDL_RenderPresent(renderer);

            //c'était les FPS


                if (couleur_h1==1&&couleur_h3==3&&couleur_b2==2&&couleur_b3==3){
                    printf("Bravo, vous avez gagner.\n");
                    cont = 0;
                }
            }
            }

        //Si la page ne s'est pas bien créée
        } else {
            //Message d'erreur
            fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
        }

        }
    //Fermeture de fichier SDL
    SDL_Quit();


    return 0;
}

void delay(unsigned int frameLimit){
    // Gestion des 60 fps (images/seconde)
    unsigned int ticks = SDL_GetTicks();

    if (frameLimit < ticks)
    {
        return;
    }

    if (frameLimit > ticks + 16)
    {
        SDL_Delay(16);
    }

    else
    {
        SDL_Delay(frameLimit - ticks);
    }
}
