#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
using namespace std;
int main(int  argc, char* argv[])
{
   
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("SDL 4.6 2022.2.14",
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          1000,800,
                                          SDL_WINDOW_SHOWN);
    SDL_Surface *surface = SDL_GetWindowSurface(window);

    SDL_Surface * p1 = IMG_Load("smile.jpg");
    SDL_Surface * p2 = IMG_Load("cry.jpg");
    SDL_Surface * p = p1;

    SDL_Rect rect{0,0};
    SDL_Event events;
    while(true)//主循环
    {
        while (SDL_PollEvent(&events))
        {
            //quit
            if(events.type == SDL_QUIT){
                SDL_FreeSurface(p1);
                SDL_FreeSurface(p2);
                SDL_FreeSurface(surface);
                SDL_DestroyWindow(window);
                SDL_Quit();
                return 0;
            }//mouse
            else if(events.type == SDL_MOUSEBUTTONDOWN){
            {
                if(events.button.button == SDL_BUTTON_LEFT)
                {
                    puts("left");
                    p = p1;
                }
                else if(events.button.button == SDL_BUTTON_RIGHT)
                {
                    puts("right");
                    p = p2;
                }
                SDL_BlitSurface(p,NULL,surface,&rect);
                SDL_UpdateWindowSurface(window);
            }
            }//keyboard
            else if(events.type == SDL_KEYDOWN){
                switch(events.key.keysym.sym){
                    case SDLK_UP:
                        rect.y-=10;
                        break;
                    case SDLK_DOWN:
                        rect.y+=10;
                        break;
                    case SDLK_LEFT:
                        rect.x-=10;
                        break;
                    case SDLK_RIGHT:
                        rect.x+=10;
                        break;
                }
                SDL_BlitSurface(p,NULL,surface,&rect);
                SDL_UpdateWindowSurface(window);
            }
        }
        
    }
}