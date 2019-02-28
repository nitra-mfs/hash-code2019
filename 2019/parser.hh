#pragma once

#include <cstdint>
#include <vector>
#include <string>

using namespace std;

using strs = vector<std::string>;

struct pic
{
    int id;

    strs tags;
    bool position; //1 vertical 0 horizontale
};


using vp = vector<pic>;
struct global_data
{
    int nb_slides;
    vp pics;
};

struct global_data gd;
