#include "cell.h"
#include <stddef.h>
#include <stdio.h>

static inline void DrawLetter(LetterCell *cell, Color fontColor){
    int posX = cell->position.x + (cell->size.x - MeasureText(cell->letter, cell->fontSize))/2;
    int posY = cell->position.y + (cell->size.y - cell->fontSize)/2;
    DrawText(cell->letter, posX, posY, cell->fontSize, fontColor);
}

void DrawLetterCell(LetterCell *cell){
    // Testing border
    bool border = false;
    Color borderColor = LIGHTGRAY;
    Color cellColor = RAYWHITE;
    Color fontColor = RAYWHITE;
    int borderSize = 0;
    switch(cell->state){
        case NO_GUESS:
        {
            border = true;
            borderColor = LIGHTGRAY;
            cellColor = RAYWHITE;
        } break;
        case WRONG_POS:
        {
            border = false;
            cellColor = YELLOW;
            fontColor = RAYWHITE;
        } break;
        case CORRECT:
        {
            border = false;
            cellColor = GREEN;
            fontColor = RAYWHITE;
        } break;
        case INCORRECT:
        {
            border = false;
            cellColor = DARKGRAY;
            fontColor = RAYWHITE;
        } break;
        case BEING_GUESSED:
        {
            border = true;
            borderColor = DARKGRAY;
            cellColor = RAYWHITE;
            fontColor = BLACK;
        } break;
        default: break;
    }
    if (border){
        borderSize = BORDER_SIZE;
        DrawRectangle(cell->position.x, cell->position.y, cell->size.x, cell->size.y, borderColor);
    }
    DrawRectangle(cell->position.x+borderSize, cell->position.y+borderSize, cell->size.x-borderSize*2, cell->size.y-borderSize*2, cellColor);

    if (cell->state != NO_GUESS && cell->letter){
        DrawLetter(cell, fontColor);
    }
}


void InitLetterCell(LetterCell *cell, int sizeX, int sizeY, int posX, int posY, int fontSize){
    cell->state = NO_GUESS;
    cell->fontSize = fontSize;
    cell->letter = NULL;
    cell->size = (Vector2){ sizeX, sizeY };
    cell->position = (Vector2){ posX, posY };
    cell->bounds = (Rectangle){ cell->position.x, cell->position.y, cell->size.x, cell->size.y };
}
