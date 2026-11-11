#include "map.h"
#include <string>
#include <cassert>
#include <stdexcept>
#include "constants.h"
#include <raylib.h>

namespace {
    // funzione helper per convertire da char a MapCells
    MapCells charToMapCells(char c) {
        switch (c) {
            case '#': return MapCells::wall;
            case '.': return MapCells::floor;
            case 'A': return MapCells::start;
            case 'B': return MapCells::end;
            default:
                assert(false && "Not valid value in the Map");
                throw std::runtime_error("Carattere non valido");
        }
    }
}

Map::Map() {
    std::vector<std::string> textMap = {
        "##############",
        "#A.........###",
        "###...##.....#",
        "#......###...#",
        "####.........#",
        "#.......##..B#",
        "##############"
    };

    // conversion
    for (const std::string& textRow : textMap) {
        std::vector<MapCells> rowMapCells;

        for (char c : textRow) {
            rowMapCells.push_back(charToMapCells(c));
        }

        mapGrid.push_back((rowMapCells));
    }

    if (!mapGrid.empty()) {
        size_t expectedCols = mapGrid[0].size();
        for (size_t i = 1; i < mapGrid.size(); ++i) {
            if (mapGrid[i].size() != expectedCols) {
                throw std::invalid_argument("La griglia fornita al costruttore non è rettangolare.");
            }
        }
    }
}

MapCells Map::getCell(int row, int col) const {
    if (row >= 0 && row < getNumRows() && col >= 0 && col < getNumCols()) {
        return mapGrid[row][col];
    } else {
        throw std::out_of_range("Errore: Cella fuori dai limiti della mappa");
    }
}

int Map::getNumCols() const {
    size_t cols = 0;
    if (!mapGrid.empty()) {
        cols = mapGrid[0].size();
    }

    int intCols = static_cast<int>(cols);
    return intCols;
}

int Map::getNumRows() const {
    const size_t rows = mapGrid.size();
    const int intRows = static_cast<int>(rows);
    return intRows;
}



