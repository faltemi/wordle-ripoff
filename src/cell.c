#include "cell.h"
#include <stddef.h>

void DrawLetterCell(LetterCell *cell){
    // ToDo
}

void InitLetterCell(LetterCell *cell, int sizeX, int sizeY, int posX, int posY, int fontSize){
    cell->state = NO_GUESS;
    cell->fontSize = fontSize;
    cell->letter = NULL;
    cell->size = (Vector2){ sizeX, sizeY };
    cell->position = (Vector2){ posX, posY };
    cell->bounds = (Rectangle){ cell->position.x, cell->position.y, cell->size.x, cell->size.y };
}
