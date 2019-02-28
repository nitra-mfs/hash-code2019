#pragma once

#include <cstdint>

#include "../../misc/point.hh"

struct ride
{
    uint id;

    point start; // start pos
    point end; // end pos
    point time; // time.x = earliest start, time.y = latest finish

    uint length; // total length of the ride
    uint sf; // latest start
    uint gap;
    uint time_dist(const ride& r, bool& who) const;
    uint distance(const ride& r) const;
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
