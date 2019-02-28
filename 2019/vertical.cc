#include "parser.hh"
extern struct global_data gd;

/*
int diff_pic(pic pic1, pic pic2)
{
    auto& t1 = pic1.tags;
    auto& t2 = pic2.tags;
    int count = 0;
    int i1 = 0, i2 = 0;

    for (; i1 < t1.size() && i2 < t2.size();)
    {
        if (t1[i1] == t2[i2])
        {
            i1++, i2++;
            continue;
        }
        count += 1;
        if (t1[i1] < t2[i2])
        {
            i1++;
            continue;
        }
        if (t1[i1] > t2[i2])
        {
            i2++;
            continue;
        }
    }

    return count + t1.size() - i1 + t2.size() - i2;
}
*/

void fusion()
{
    int nb = gd.picsV.size();
    for (int i = 0; i < nb; i += 2)
    {
        pic p;
        p.id = gd.picsV[i].id;
        p.id2 = gd.picsV[i+1].id;
        p.position = 1;
        p.tags.insert(gd.picsV[i].tags.begin(), gd.picsV[i].tags.end());
        p.tags.insert(gd.picsV[i+1].tags.begin(), gd.picsV[i+1].tags.end());
        gd.pics.push_back(p);
    }
}
