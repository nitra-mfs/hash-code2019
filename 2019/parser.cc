#include "parser.hh"

#include <fstream>
#include <iostream>
#include <vector>
#include <string>

static uint count = 0;
extern global_data gd;

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

void read_input_file(std::istream& in)
{
    in >> gd.nb_slides;

    for (int i = 0; i < gd.nb_slides; ++i)
    {
        pic p;
        in >> p;
        if (p.position)
            gd.pics.push_back(p);
        else
            gd.picsV.push_back(p);
    }
}
