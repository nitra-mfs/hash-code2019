#include "stripe.hh"

using namespace std;

void Stripe::process(const rides& rv)
{
    for (auto i = 0u; i < rv.size(); ++i)
    {
        for (auto j = i + 1; j < rv.size(); ++j)
        {
            const auto& a = rv[i];
            const auto& b = rv[j];
            map_[make_pair(a, b)] = a.distance(b);
        }
    }
}

void Stripe::sort()
{
    Comparator compFunctor = [](std::pair<line, int> elem1,
                                std::pair<line, int> elem2) {
        return elem1.second < elem2.second;
    };

    set_ = std::set<std::pair<line, double>, Comparator>(
        map_.begin(), map_.end(), compFunctor);
}