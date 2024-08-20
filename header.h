#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <math.h>

#include "SDL2/SDL.h"


#define SCREEN_WIDTH 1280 
#define SCREEN_HEIGHT 720

#define CELL_SIZE 2

void draw_grid(SDL_Renderer *renderer, int rows, int cols);
void draw(SDL_Renderer *renderer, int *cells, int rows, int cols);
void game_of_life(int *cells, int *cells_new, int rows, int cols);

#endif
