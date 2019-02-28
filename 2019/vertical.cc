#include "parser.hh"
extern struct global_data gd;

int diff_pic(pic pic1, pic pic2)
{
    auto& t1 = pic1.tags;
    auto& t2 = pic2.tags;
    int count = 0;
    int i1 = 0, i2 = 0;

    for (auto it1 = t1.begin(), it2 = t2.begin (); it1 != t1.end() && it2 != t2.end();)
    {
        if (*it1 == *it2)
        {
            it1++, it2++;
            i1++, i2++;
            continue;
        }
        count += 1;
        if (*it1 < *it2)
        {
            i1++;
            it1++;
            continue;
        }
        if (*it1 > *it2)
        {
            i2++;
            it2++;
            continue;
        }
    }

    return count + t1.size() - i1 + t2.size() - i2;
}

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

void fusion_opti()
{
    for (int i = 0; i < (int)gd.picsV.size(); ++i)
    {
        if (gd.picsV[i].isUsed)
            continue;

        int max_index;
        int max_val = -1;

        for (int j = 0; j < (int)gd.picsV.size(); ++j)
        {
            if (i == j || gd.picsV[j].isUsed)
                continue;

            int f = diff_pic(gd.picsV[i], gd.picsV[j]);
            if (max_val < f)
            {
                max_val = f;
                max_index = j;
            }
        }

        pic p;
        p.id = gd.picsV[i].id;
        p.id2 = gd.picsV[max_index].id;
        p.position = 1;
        p.tags.insert(gd.picsV[i].tags.begin(), gd.picsV[i].tags.end());
        p.tags.insert(gd.picsV[max_index].tags.begin(), gd.picsV[max_index].tags.end());
        gd.pics.push_back(p);

        gd.picsV[i].isUsed = true;
        gd.picsV[max_index].isUsed = true;
    }
}
