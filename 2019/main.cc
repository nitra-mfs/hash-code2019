#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cstdlib>
#include <limits>
#include <cstdint>
#include <string>
#include <fstream>
#include <ctime>

#include "slide.hh"
#include "parser.hh"
#include "vertical.hh"

global_data gd;

template<class Out>
Out& operator<<(Out& out, const Slide& s)
{
    out << s.pics_.size();
    for (const auto& v : s.pics_)
    {
        out << v.id;
        if (v.position)
            out << ' ' << v.id2;
        out << endl;
    }
    return out;
}

int main()
{
    read_input_file(std::cin);
    fusion();
    srand(time(nullptr));
    Slide s;
    s.sort();
    //s.some_bubble();
    cout << s;
    return 0;
}
