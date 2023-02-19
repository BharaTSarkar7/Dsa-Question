#include <stdio.h>
#include <string.h>

void rev(char *str)
{
    if (!(*str))
    {
        return;
    }
    rev(str + 1);
    printf("%c", str[0]);
}
int main()
{
    rev("santosh");
    return 0;
}