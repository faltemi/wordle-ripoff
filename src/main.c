#include "raylib.h"
#include <stddef.h>

#define PLAYER_GUESSES  6
#define NUM_LETTERS     5

typedef enum GameScreen { LOGO, TITLE, GAMEPLAY, ENDING } GameScreen;

// LetterCell Structure
typedef struct LetterCell {
    Vector2 position;
    Vector2 size;
    Rectangle bounds;
    bool active;
    char letter;
} LetterCell;

int main(){
    // Initialization
    // ----------------------------------------------------------------
    // Window setup parameters
    const int screenWidth = 800;
    const int screenHeight = 600;
    const char *windowTitle = "Wordle Clone";

    InitWindow(screenWidth, screenHeight, windowTitle);
    // NOTE: Load resources (textures, fonts, audio) after Window initialization
    
    // Setup initial game state
    GameScreen screen = LOGO;

    int framesCounter = 0;
    int gameResult = -1;

    LetterCell letterCells[PLAYER_GUESSES][NUM_LETTERS] = { 0 };
    // Initialize letter cells
    for (int r = 0; r < PLAYER_GUESSES; r++){
        for (int c = 0; c < NUM_LETTERS; c++){
            letterCells[r][c].active = false;
            letterCells[r][c].letter = '\0';
            letterCells[r][c].size = (Vector2){ screenWidth/NUM_LETTERS, 20 };
            letterCells[r][c].position = (Vector2){ c*letterCells[r][c].size.x, r*letterCells[r][c].size.y + 100 }; // Add y offset
            letterCells[r][c].bounds = (Rectangle){ letterCells[r][c].position.x, letterCells[r][c].position.y, letterCells[r][c].size.x, letterCells[r][c].size.y };
        }
    }

    // Desired framerate
    SetTargetFPS(60);
    // ----------------------------------------------------------------

    // Main loop
    while(!WindowShouldClose()){
        // Update
        // ------------------------------------------------------------
        switch (screen){
            case LOGO:
            {
                framesCounter++;
                // After 3 seconds, change to title screen
                if(framesCounter > 180){
                    screen = TITLE;
                    framesCounter = 0;
                }
            } break;
            case TITLE:
            {
                framesCounter++;
                if (IsKeyPressed(KEY_ENTER)) screen = GAMEPLAY;
            } break;
            case GAMEPLAY:
            {
                framesCounter++;
                // ToDo: Gameplay logic
                if (IsKeyPressed(KEY_ENTER)) screen = ENDING;
            } break;
            case ENDING:
                {
                    framesCounter++;
                    // Game end logic
                    if (IsKeyPressed(KEY_ENTER)) screen = TITLE;
                } break;
            default: break;
        }
        // ------------------------------------------------------------


        // Draw
        // ------------------------------------------------------------
        BeginDrawing();
            ClearBackground(RAYWHITE);
            switch(screen){
                case LOGO:
                {
                    DrawText("LOGO SCREEN", 20, 20, 20, DARKBLUE);
                    DrawText("WAIT for 3 seconds...", 290, 220, 20, GRAY);
                } break;
                case TITLE:
                {
                    DrawRectangle(0, 0, screenWidth, screenHeight, GREEN);
                    DrawText("TITLE SCREEN", 20, 20, 40, DARKGREEN);
                    // Every half second toggle text (60 fps)
                    if ((framesCounter/30)%2 == 0)
                        DrawText("PRESS [ENTER] to START", GetScreenWidth()/2 - MeasureText("PRESS [ENTER] to START", 20)/2, GetScreenHeight()/2 + 60, 20, DARKGRAY);
                } break;
                case GAMEPLAY:
                {
                    DrawRectangle(0, 0, screenWidth, screenHeight, PURPLE);
                    DrawText("GAMEPLAY SCREEN", 20, 20, 40, MAROON);
                    DrawText("PRESS ENTER or TAP to JUMP to ENDING SCREEN", 130, 220, 20, MAROON);
                } break;
                case ENDING:
                {
                    DrawRectangle(0, 0, screenWidth, screenHeight, BLUE);
                    DrawText("ENDING SCREEN", 20, 20, 40, DARKBLUE);
                    DrawText("PRESS ENTER or TAP to RETURN to TITLE SCREEN", 120, 220, 20, DARKBLUE);
                } break;
                default: break;
            }
        EndDrawing();
        // ------------------------------------------------------------
    }

    // De-Initialize
    // ----------------------------------------------------------------

    CloseWindow();
    // ----------------------------------------------------------------
    return 0;
}