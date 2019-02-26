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

    uint time_dist(const ride& r, bool& who) const
    {
        uint a = time.x > r.time.y ? (time.x - r.time.y) : (r.time.y - time.x);
        uint b = time.y > r.time.x ? (time.y - r.time.x) : (r.time.x - time.y);
        if (a < b)
        {
            who = false; // Depart de this, Arrivee de r
            return a;
        } else
        {
            who = true;
            return b;
        }
    }
    uint distance(const ride& r) const
    {
        bool who = false;
        uint t = time_dist(r, who);
        return who ? (t * end.distance(r.start)) : (t * start.distance(r.end));
    }
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
