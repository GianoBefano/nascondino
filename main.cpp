#include <raylib.h>
#include "map.h"
#include "draw.h"
#include "constants.h"
#include "draw.h"
#include "constants.h"

int main() {

    const int monitor = GetCurrentMonitor();
    const int screenWidth = GetMonitorWidth(monitor);
    const int screenHeight = GetMonitorHeight(monitor);

    InitWindow(screenWidth, screenHeight, "Prima finestra di prova");
    SetTargetFPS(60);
    Map map;

    // main loop
    while (!WindowShouldClose()) {   // detects window close button or ESC key

        BeginDrawing();

            ClearBackground(constants::backgroundColor);
            draw_map(map);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
