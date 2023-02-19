#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    vector<int> a{1, 2, 3};
    a.push_back(5);
    
    for (int &i : a)
    {
        cout << i << " ";
    }

    return 0;
}