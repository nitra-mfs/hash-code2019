#pragma once

#include <cmath>
#include <cstdint>
using uint = uint32_t;

struct point
{
    point(uint x_ = 0, uint y_ = 0)
        : x(x_)
        , y(y_)
    {}
    uint x;
    uint y;
    uint distance(const point& p) const
    {
        return ((x > p.x) ? (x - p.x) : (p.x - x))
            + ((y > p.y) ? (y - p.y) : (p.y - y));
    }
};