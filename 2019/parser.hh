#pragma once

#include <cstdint>
#include <vector>
#include <string>
#include <set>

using namespace std;

using strs = set<std::string>;

struct pic
{
    int id;
    int id2 = -1;
    bool isUsed = false;

    strs tags;
    bool position; //1 vertical 0 horizontale
};

using vp = vector<pic>;
struct global_data
{
    int nb_slides;
    vp pics; //full horizontal
    vp picsV; //full vertical
};

void read_input_file(std::istream& in);
