#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <math.h>

#include "SDL2/SDL.h"


#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#define CELL_SIZE 20

void draw_grid(SDL_Renderer *renderer, int rows, int cols);
void draw(SDL_Renderer *renderer, int *cells, int rows, int cols);

#endif
