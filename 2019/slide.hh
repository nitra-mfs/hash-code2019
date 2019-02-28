#pragma once

#include "parser.hh"
#include <algorithm>

#define ITER 100

class Slide
{
public:
    Slide();
    int score();
    void sort();
    void prepro();
    void bubble();
    void some_bubble();
    void sort_size();
    void cut_v();
    vp pics_;
    int score_;
};

int min3(const pic& a, const pic& b);