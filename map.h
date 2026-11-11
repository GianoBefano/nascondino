#ifndef NASCONDINO_MAP_H
#define NASCONDINO_MAP_H

#include <vector>


enum class MapCells {
    start,
    wall,
    end,
    floor,
};

class Map {
private:
    std::vector<std::vector<MapCells>> mapGrid;

public:
    Map();

    MapCells getCell(int row, int col) const;
    int getNumRows() const;
    int getNumCols() const;
};


#endif //NASCONDINO_MAP_H
