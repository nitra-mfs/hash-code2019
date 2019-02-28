#include "parser.hh"

#include <fstream>
#include <iostream>
#include <vector>
#include <string>

static uint count = 0;

template <class In>
In& operator>>(In& in, pic& p)
{
    p.id = count;
    count += 1;

    std::string s;
    in >> s;
    p.position = s == "H";

    int i;
    in >> i;
    for (int a = 0; a < i; ++a)
    {
        in >> s;
        p.tags.insert(s);
    }
    return in;
}

std::vector<pic> read_input_file(std::istream& in)
{
    in >> gd.nb_slides;

    auto pics = std::vector<pic>(gd.nb_slides);
    for (auto& p : pics)
        in >> p;

    gd.pics = pics;
    return pics;
}
