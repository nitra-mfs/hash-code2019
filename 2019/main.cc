#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cstdlib>
#include <limits>
#include <cstdint>
#include <string>
#include <fstream>

#include "slide.hh"
#include "parser.hh"

template<class Out>
Out& operator<<(Out& out, const Slide& s)
{
    out << s.pics_.size();
    for (const auto& v : s.pics_)
    {
        out << v.id;
        if v.position = 1;
            out << v.id2;
    }
    return out;
}

int main()
{
    return 0;
}
