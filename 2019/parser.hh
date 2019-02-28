#pragma once

#include <cstdint>
#include <vector>

using namespace std

using strs = vector<std::string>

struct pic
{
    int id;

    strs tags;
    bool position; //1 vertical 0 horizontale
};

struct global_data
{
    int nb_slides;
};

struct global_data gd;
