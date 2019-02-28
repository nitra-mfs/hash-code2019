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
        score_ += min3(pics_[i], pics_[i+1]);
    }
    return score_;
}
int min3(const pic& a, const pic& b)
{
   int x = a.tags.size();
   int y = 0;
   int z = b.tags.size();
   for (const auto& s : b.tags)
   {
       if (a.tags.find(s) != a.tags.end())
       {
           --x;
           ++y;
           --z;
       }
   } 
   x = x < y ? x : y;
   x = z < x ? z : x;
   return x;
}
