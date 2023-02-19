#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    int i, j, flag = 0;
    vector<int> ans;
    for (i = 0; i < nums.size(); i++)
    {
        for (j = i + 1; j < nums.size(); j++)
        {
            if ((nums[i] + nums[j]) == target)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            break;
        }
    }
    ans.push_back(i);
    ans.push_back(j);
    return ans;
}

int main(int argc, char *argv[])
{
    vector<int> num{2, 7, 11, 15};
    int tra = 9;
    vector<int> sum = twoSum(num, tra);
    for (int i = 0; i < sum.size(); i++)
    {
        cout << sum[i] << " ";
    }

    return 0;
}