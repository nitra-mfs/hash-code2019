#pragma once

#include <map>
#include <utility>
#include <vector>
#include <set>
#include <functional>
#include "../../misc/point.hh"
#include "../parser/parser.hh"


class Stripe
{
public:
    using rides = std::vector<ride>;
    using line = std::pair<ride, ride>;
    using Comparator = std::function<bool(std::pair<line, double>, std::pair<line, int>)>;
    Stripe();
    ~Stripe();
    void process(const rides& r);
    void sort();
protected:
    std::map<line, double> map_;
    std::set<std::pair<line, double>, Comparator> set_;
    bool *used_;
};