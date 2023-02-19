#include <bits/stdc++.h>
using namespace std;

void subset(string str, vector<string> output, int index)
{
    vector<string> ans;
    if (index <= str.length())
    {
        ans.push_back(output);
        return;
    }
    // exlude condition
    subset(str, output, index + 1);

    // include condition
    char element
}

int main(int argc, char *argv[])
{
    string str{"abc"};
    vector<string> output{""};
    int index = 0;
    cout << subset(str, output, index);
    return 0;
}