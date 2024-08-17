#include <stdio.h>

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
                               1280, 720,
                               SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(window,
                                   -1,
                                   SDL_RENDERER_ACCELERATED);
    
    int rows = SCREEN_WIDTH / CELL_SIZE;
    int cols = SCREEN_HEIGHT / CELL_SIZE;
    printf("%d %d\n", rows, cols);
    int cells[rows*cols];

    int count = 0;

    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            if (count % 31 == 0)
            {
                cells[i*rows + j] = 1;
            }
            else 
            {
                cells[i*rows + j] = 0;
            }
            count++;
        }
    }
    
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            printf("%d ", cells[i*rows + j]);
        }
        printf("\n");
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
        
        draw_grid(renderer, rows, cols);
        draw(renderer, cells, rows, cols); 

        SDL_RenderPresent(renderer);
        SDL_Delay(100);
    }
    
    SDL_DestroyWindow(window);
    SDL_Quit();
}

