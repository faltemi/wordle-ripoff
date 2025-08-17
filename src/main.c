#include "raylib.h"

int main(){
    InitWindow(800, 600, "Wordle Clone");
    SetTargetFPS(60);

    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Testing Raylib.", 20, 20, 20, DARKBLUE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}