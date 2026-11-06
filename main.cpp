#include <raylib.h>

int main() {

    // initialization
    constexpr int screenWidth = 800;
    constexpr int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Prima finestra di prova");
    SetTargetFPS(60);

    // main loop
    while (!WindowShouldClose()) {   // detects window close button or ESC key

        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Prima prova", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
