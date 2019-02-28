#pragma once

#include "parser.hh"
#include <algorithm>

#define ITER 1000

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
protected:
    vp pics_;
    int score_;
};

int min3(const pic& a, const pic& b);