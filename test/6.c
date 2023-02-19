#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    float sum = 0.0;
    int sign = 1;

    // Read in the value of n
    printf("Enter the limit: ");
    scanf("%d", &n);

    // Evaluate the series
    for (int i = 1; i <= n; i = i + 2)
    {
        int fact = 1;
        for (int j = 1; j <= i; j++)
        {
            fact = fact * j;
        }
        printf("%d ", fact);
        sum += (float)(sign * (i / fact));
        sign = -sign;
    }

    // Print the result
    printf("The sum of the series is: %.4f\n", sum);

    return 0;
}