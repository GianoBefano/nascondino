// In draw.cpp
#include "draw.h"
#include "map.h"
#include "raylib.h"
#include "constants.h"

// Helper locale al file di rendering: calcola l'offset solo quando serve disegnare
static Vector2 get_map_offset(const Map& map) {
    float mapWidth = map.getNumCols() * constants::pixelsForCell;
    float mapHeight = map.getNumRows() * constants::pixelsForCell;

    return {
        (GetScreenWidth() - mapWidth) / 2.0f,
        (GetScreenHeight() - mapHeight) / 2.0f
    };
}

void draw_map(const Map& map) {
    int rows = map.getNumRows();
    int cols = map.getNumCols();

    Vector2 offset = get_map_offset(map);

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            MapCells tile = map.getCell(row, col);

            Rectangle rec = {
                offset.x + static_cast<float>(col * constants::pixelsForCell),
                offset.y + static_cast<float>(row * constants::pixelsForCell),
                static_cast<float>(constants::pixelsForCell),
                static_cast<float>(constants::pixelsForCell)
            };

            Color color = BLACK;
            switch (tile) {
                case MapCells::wall:  color = constants::wallColor; break;
                case MapCells::floor: color = constants::floorColor; break;
                case MapCells::start: color = constants::startColor; break;
                case MapCells::end:   color = constants::endColor; break;
            }

            DrawRectangleRec(rec, color);
            DrawRectangleLinesEx(rec, 0.5f, constants::borderCellColor);
        }
    }
}