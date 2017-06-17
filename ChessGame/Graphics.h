#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <stdint.h>
#include "Globals.h"
#include "Board.h"

class Graphics
{

public:
    Graphics(void);
    void Update(Board CurrBoard);

private:
    uint32_t _Turn;
};

#endif