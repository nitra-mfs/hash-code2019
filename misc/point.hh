#pragma once

struct point
{
    point(uint x_ = 0, uint y_ = 0)
        : x(x_)
        , y(y_)
    {}
    uint x;
    uint y;
};