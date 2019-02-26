#include <iostream>
#include <fstream>
#include <vector>
#include "parser.hh"

uint absdiff(uint a, uint b)
{
    return a < b ? b-a : a-b;
}

uint compute_length(point start, point end)
{
    return absdiff(start.x, end.x) + absdiff(start.y, end.y);
}

template<class In>
In& operator>>(In& in, ride& r)
{
    in >> r.start >> r.end >> r.time;
    r.length = compute_length(r.start, r.end);
    r.sf = r.time.y - r.length;
    r.gap = r.sf - r.time.x;
    return in;
}

std::vector<ride> read_input_file(std::istream& in)
{
    in >> gd.rows
       >> gd.cols
       >> gd.nbVehicles
       >> gd.nbRides
       >> gd.bonus
       >> gd.nbSteps;

    auto rides = std::vector<ride>(gd.nbRides);
    for (auto& r: rides)
        in >> r;

    return rides;
}

int main()
{
    std::ifstream in("../tests/a_example.in");
    auto r = read_input_file(in);
    return 0;
}
