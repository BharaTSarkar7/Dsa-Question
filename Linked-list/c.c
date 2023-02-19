// #include <stdio.h>
// // int main()
// // {
// //     int num = 8, todo = num;
// //     int bit = 1;
// //     while (todo != 0)
// //     {
// //         num = num ^ bit;
// //         bit = bit << 1;
// //         todo = todo >> 1;
// //     }
// //     printf("%d", num);
// //     return 0;
// // }

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *ptr = (int *)malloc(sizeof(int));
    printf("%d\t", ptr);
    ptr = (int *)realloc(ptr, sizeof(int) * 2);
    printf("%d\t", (ptr + 1));
    ptr = (int *)realloc(ptr, sizeof(int) * 3);
    printf("%d\t", (ptr + 2));
    ptr = (int *)realloc(ptr, sizeof(int) * 4);
    printf("%d\t", (ptr + 3));

    return 0;
}