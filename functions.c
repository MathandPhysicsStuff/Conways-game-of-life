#include "header.h"

void draw_grid(SDL_Renderer *renderer, int rows, int cols)
{

    for (int i = 0; i <= rows; i++)
    {
        for (int j = 0; j <= cols; j++)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderDrawLine(renderer, i*CELL_SIZE, 0, i*CELL_SIZE, SCREEN_HEIGHT);
            SDL_RenderDrawLine(renderer, 0, j*CELL_SIZE, SCREEN_WIDTH, j*CELL_SIZE);
        }
    }
}

void draw(SDL_Renderer *renderer, int *cells, int rows, int cols)
{
    SDL_Rect cell;
    cell.w = CELL_SIZE;
    cell.h = CELL_SIZE;

    for (int i = 0; i < cols; i++)
    {
        cell.y = i * CELL_SIZE;
        for (int j = 0; j < rows; j++)
        {
            cell.x = j * CELL_SIZE;
            if (cells[i*rows + j] == 1)
            {
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                SDL_RenderFillRect(renderer, &cell);
            }
        }
    }
}


void game_of_life(int *cells, int *cells_new, int rows, int cols)
{
    int i, j;
    int p = 0; 
    int life = 0; 
    
    //updates cells
    for (i = 0; i < cols; i++)
    {
        for (j = 0; j < rows; j++)
        {
            p = i*rows + j;

            life += cells[(p+1)];
            life += cells[(p-1)]; 

            life += cells[(p-rows-1) % (rows*cols)];
            life += cells[(p-rows) % (rows*cols)];
            life += cells[(p-rows+1) % (rows*cols)];

            life += cells[(p+rows-1) % (rows*cols)];
            life += cells[(p+rows) % (rows*cols)];
            life += cells[(p+rows+1) % (rows*cols)];

            if (cells[p] == 1 && life < 2) cells_new[p] = 0;
            if (cells[p] == 1 && (life == 2 || life == 3)) cells_new[p] = 1;
            if (cells[p] == 1 && life > 3) cells_new[p] = 0;
            if (cells[p] == 0 && life == 3) cells_new[p] = 1;

            life = 0;
        }
    }
    
    for (i = 0; i < rows*cols; i++)
    {
        cells[i] = cells_new[i];
    }
}



















