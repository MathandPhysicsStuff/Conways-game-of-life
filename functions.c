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
