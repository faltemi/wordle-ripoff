#include "raylib.h"

typedef enum GameScreen { LOGO, TITLE, GAMEPLAY, ENDING } GameScreen;

int main(){
    // Window setup parameters
    const int screenWidth = 800;
    const int screenHeight = 600;
    const char *windowTitle = "Wordle Clone";

    InitWindow(screenWidth, screenHeight, windowTitle);
    
    // Setup initial game state
    GameScreen screen = LOGO;

    int framesCounter = 0;
    int gameResult = -1;

    // Desired framerate
    SetTargetFPS(60);

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
                    DrawText("PRESS ENTER or TAP to JUMP to GAMEPLAY SCREEN", 120, 220, 20, DARKGREEN);
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
    // ------------------------------------------------------------

    CloseWindow();
    // ------------------------------------------------------------
    return 0;
}