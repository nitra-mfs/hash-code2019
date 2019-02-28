#include "slide.hh"

extern struct global_data gd;

Slide::Slide()
    : pics_(), score_(0)
{}

int Slide::score()
{
    score_ = 0;
    for (auto i = 0u; i < pics_.size() - 1; ++i)
    {
        score += min3(pics_[i], pics_[i+1]);
    }
    return score_;
}