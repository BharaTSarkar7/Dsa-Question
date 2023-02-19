#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    set<int> check;
    vector<int> can{1, 2, 3, 4, 4};
    vector<int>::iterator i;

    // My Approch to find duplicate

    // while (j < can.size())
    // {
    //     check.insert(can[j]);
    //     i++;
    //     j++;
    //     if (check.size() != i)
    //     {
    //         cout << "it contain duplicate" << endl;
    //         exit(0);
    //     }
    // }

    // Improved Approch

    for (i = can.begin(); i != can.end(); i++)
    {
        if (check.find(*i) != check.end())
        {
            cout << "It contain Duplicate" << endl;
            exit(0);
        }
        else
        {
            check.insert(*i);
        }
    }

    cout << "run successfully" << endl;
    return 0;
}