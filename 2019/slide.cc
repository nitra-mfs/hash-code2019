#include "slide.hh"
#include <iostream>

extern global_data gd;

using namespace std;

Slide::Slide()
    : pics_(gd.pics)
    , score_(0)
{}

int Slide::score()
{
    score_ = 0;
    for (auto i = 0u; i < pics_.size() - 1; ++i)
    {
        score_ += min3(pics_[i], pics_[i + 1]);
    }
    return score_;
}

static void swap(pic& a, pic& b)
{
    pic tmp = a;
    a = b;
    b = tmp;
}

void Slide::sort()
{
    int b = 0;
    auto bidx = 0u;
    int c = 0;
    for (auto i = 0u; i < pics_.size() - 1; ++i)
    //for (auto i = 0u; i < 500; ++i)
    {
        b = 0;
        bidx = 0;
        c = 0;
        int tmp = 0;
        for (auto j = i + 1; j < pics_.size(); ++j)
        {
            tmp = min3(pics_[i], pics_[j]);
            if (tmp > b)
            {
                b = tmp;
                bidx = j;
                ++c;
                if (c > 2)
                    break;
            }
        }
        if (!(i % 25))
            cerr << i << " / " << pics_.size() << endl;
        swap(pics_[bidx], pics_[i + 1]);
    }
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

void Slide::prepro()
{}

void Slide::bubble()
{
    int ssc = score_;
    int ns = 0;
    int tries = 0;
    while (true)
    {
        int x = rand() % pics_.size();
        int y = x;
        while (y == x)
            y = rand() % pics_.size();
        swap(pics_[x], pics_[y]);
        if (score() > score_)
            break;
        swap(pics_[x], pics_[y]);
        if (tries > 1)
            break;
        ++tries;
    }
}

void Slide::some_bubble()
{
    for (auto i = 0u; i < ITER; ++i)
        bubble();
}

static bool mtags(pic& a, pic& b)
{
    return a.tags.size() > b.tags.size();
}

void Slide::sort_size()
{
    std::sort(pics_.begin(), pics_.end(), mtags);
}

void Slide::cut_v()
{
    for (auto i = pics_.size() - 1; i >= 0; --i)
    {
        if (pics_[i].position)
        {
            pics_.erase(pics_.begin() + i);
        }
    }
}

void Slide::shuffle()
{
    std::random_shuffle(pics_.begin(), pics_.end());
}