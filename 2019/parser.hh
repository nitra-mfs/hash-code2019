#pragma once

#include <cstdint>

using strs = vector<std::string>

struct pic
{
    int id;

    strs tags;
    int position;
};

struct global_data
{
    int nb_slides;
};

struct global_data gd;
