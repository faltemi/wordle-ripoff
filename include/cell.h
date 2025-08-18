#ifndef CELL_H
#define CELL_H

#include "raylib.h"

typedef enum CellState {
    NO_GUESS,
    WRONG_POS,
    CORRECT,
    INCORRECT,
    BEING_GUESSED
} CellState;

typedef struct LetterCell {
    Vector2 position;
    Vector2 size;
    Rectangle bounds;
    char *letter;
    int fontSize;
    CellState state;
} LetterCell;


void DrawLetterCell(LetterCell *cell);
void InitLetterCell(LetterCell *cell, int sizeX, int sizeY, int posX, int posY, int fontSize);
#endif // CELL_H