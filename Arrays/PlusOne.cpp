#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    vector<int> digits{0, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9};
    if (digits.back() < 9)
    {
        int num = digits.back();
        digits.back() = num + 1;
    }
    else
    {
        int i = digits.size() - 1;
        while (1)
        {

            if (i < 0)
            {
                digits.insert(digits.begin(), 1);
                break;
            }

            if (digits[i] == 9)
            {
                digits[i--] = 0;
            }
            else
            {
                digits[i]++;
                break;
            }
        }
        for (int i = 0; i < digits.size(); i++)
        {
            cout << digits[i] << " ";
        }
    }
    return 0;
}