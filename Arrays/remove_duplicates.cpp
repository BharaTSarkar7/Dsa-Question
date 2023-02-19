#include <bits/stdc++.h>
using namespace std;

int RemoveDup(vector<int> &nums)
{
    set<int> check;
    set<int>::iterator s;
    vector<int>::iterator i;
    for (i = nums.begin(); i != nums.end(); i++)
    {
        check.insert(*i);
    }
    nums.clear();
    for (s = check.begin(); s != check.end(); s++)
    {
        nums.push_back(*s);
    }
    int size = check.size();
    return size;
}

int main(int argc, char *argv[])
{
    vector<int> nums{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    int N = RemoveDup(nums);
    for (int i = 0; i < N; i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}