#pragma once

#include "parser.hh"

class Slide
{
public:
    Slide();
    int score();
protected:
    vp pics_;
    int score_;
};

int min3(const pic& a, const pic& b);