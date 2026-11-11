#ifndef NASCONDINO_CONSTANTS_H
#define NASCONDINO_CONSTANTS_H

#include <raylib.h>

namespace constants {
    inline constexpr float pixelsForCell {32.0f};

    // colors
    inline constexpr Color backgroundColor = {.r = 244, .g = 235, .b = 217, .a = 255};
    inline constexpr Color wallColor       = {.r = 91,  .g = 70,  .b = 54,  .a = 255};
    inline constexpr Color floorColor      = {.r = 168, .g = 198, .b = 134, .a = 255};
    inline constexpr Color startColor      = {.r = 159, .g = 211, .b = 230, .a = 255};
    inline constexpr Color endColor        = {.r = 179, .g = 157, .b = 219, .a = 255};
    inline constexpr Color borderCellColor      = {.r = 151, .g = 181, .b = 118, .a = 255};
}

#endif //NASCONDINO_CONSTANTS_H