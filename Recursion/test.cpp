#include <bits/stdc++.h>
using namespace std;

// int peak_element(int a[], int n)
// {
//     int start = 0, end = n - 1;
//     int mid = start + (end - start) / 2;
//     while (start < end)
//     {
//         if (a[mid] < a[mid + 1])
//         {
//             start = mid + 1;
//         }
//         else
//         {
//             end = mid;
//         }
//         mid = start + (end - start) / 2;
//     }
//     return start;
// }

// int main(int argc, char *argv[])
// {
//     int a[]{3, 5, 4, 2, 1};
//     int index = peak_element(a, 5);

//     cout << "Peak of array is at index " << index + 1 << endl;

//     return 0;
// }

// Time Complexity is O(log n)




// int main()
// {
//     string str{"aabsciasn"};
//     int i, count = 0;
//     for (i = 0; i <= str.length(); i++)
//     {
//         if (str[0] == 'a')
//         {
//             str.erase(str.begin());
//             count++;
//         }
//         if (str[i] == 'a')
//         {
//             str.erase(str.cbegin() + i);

//             count++;
//         }
//     }
//     for (i = 0; i < count; i++)
//     {
//         str.push_back('a');
//     }
//     cout << str << endl;
// }




// int f(int &x, int c)

// {

//     c = c - 1;

//     if (c == 0)
//         return 1;

//     x = x + 1;

//     return f(x, c) * x;
// }

// int main()
// {
//     int a = 5;
//     cout << f(a, 5) << endl;
// }