#pragma once

#include <cstdint>
#include "../../misc/point.hh"

using uint = uint32_t;

struct ride
{
    point start; // start pos
    point end; // end pos
    point time; // time.x = earliest start, time.y = latest finish

    uint length; // total length of the ride
    uint sf; // latest start
    uint gap;
};

struct global_data
{
    uint rows;
    uint cols;
    uint nbVehicles;
    uint nbRides;
    uint bonus;
    uint nbSteps;
};

struct global_data gd;
