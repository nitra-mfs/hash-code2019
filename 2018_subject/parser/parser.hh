#pragma once

struct ride {
    uint a, b; // start pos
    uint x, y; // end pos
    uint s; // earliest start
    uint f; // latest finish

    uint length; // total length of the ride
    uint sf; // latest start
    uint gap;
    uint distance() const;
};

uint R, C, F, N, B, T;
vector<ride> rides;
