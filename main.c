#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "SDL2/SDL.h"
#include "header.h"

static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;

int main()
{

    if (SDL_Init(SDL_INIT_VIDEO) < 0) printf("SDL2 video failed to initialize: \n", SDL_GetError());
    else printf("System is ready to go!\n");

    window = SDL_CreateWindow("Hello SDL",
                               SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                               SCREEN_WIDTH, SCREEN_HEIGHT,
                               SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(window,
                                   -1,
                                   SDL_RENDERER_ACCELERATED);
    
    srand(time(0));

    int rows = SCREEN_WIDTH / CELL_SIZE;
    int cols = SCREEN_HEIGHT / CELL_SIZE;
    int cells[rows*cols];
    int cells_new[rows*cols];

    int x = 0;

    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
                //cells[i*rows + j] = 0;
                cells_new[i*rows + j] = 0;
                
                x = rand() % 100;
                if (x < 20) cells[i*rows + j] = 1;
                else cells[i*rows + j] = 0;
                
        }
    }
    
    SDL_bool running = SDL_TRUE;
    while (running == SDL_TRUE)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = SDL_FALSE;
                break;
            }
                
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        
        //draw_grid(renderer, rows, cols);
        draw(renderer, cells, rows, cols); 
        game_of_life(cells, cells_new, rows, cols); 

        SDL_RenderPresent(renderer);
        SDL_Delay(60);
    }
    
    SDL_DestroyWindow(window);
    SDL_Quit();
}

