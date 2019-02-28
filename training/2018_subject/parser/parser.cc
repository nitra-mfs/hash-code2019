#include "parser.hh"

#include <fstream>
#include <iostream>
#include <vector>

static uint count = 0;

uint absdiff(uint a, uint b)
{
    return a < b ? b - a : a - b;
}

uint compute_length(point start, point end)
{
    return absdiff(start.x, end.x) + absdiff(start.y, end.y);
}

template <class In>
In& operator>>(In& in, ride& r)
{
    r.id = count;
    count += 1;
    in >> r.start >> r.end >> r.time;
    r.length = compute_length(r.start, r.end);
    r.sf = r.time.y - r.length;
    r.gap = r.sf - r.time.x;
    return in;
}

std::vector<ride> read_input_file(std::istream& in)
{
    in >> gd.rows >> gd.cols >> gd.nbVehicles >> gd.nbRides >> gd.bonus
        >> gd.nbSteps;

    auto rides = std::vector<ride>(gd.nbRides);
    for (auto& r : rides)
        in >> r;

    return rides;
}

uint ride::time_dist(const ride& r, bool& who) const
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

uint ride::distance(const ride& r) const
{
    bool who = false;
    uint t = time_dist(r, who);
    return who ? (t * end.distance(r.start)) : (t * start.distance(r.end));
}

int main()
{
    std::ifstream in("../tests/a_example.in");
    auto r = read_input_file(in);
    return 0;
}
