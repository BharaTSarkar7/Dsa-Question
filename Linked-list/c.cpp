#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int point = 0;
    int a[5] = {4, 1, 8, 4, 5}, b[6] = {5, 6, 1, 8, 4, 5};
    vector<int> c;
    vector<int> d;
    for (int i = 0; i < 5; i++)
    {
        c.push_back(a[i]);
    }
    for (int i = 0; i < 6; i++)
    {
        d.push_back(b[i]);
    }
    int i = 5, j = 6;
    while (c[i] == d[j])
    {
        i--;
        j--;
        point++;
    }
    printf("%d", point);
    return 0;
}