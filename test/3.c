#include <stdio.h>

int main()
{
    // Declare variables to store the ratings
    int rating1, rating2, rating3;

    printf("\nRating varying from 1 to 10\n");

    // ask the user to enter the ratings
    printf("Enter the first rating: ");
    scanf("%d", &rating1);
    printf("Enter the second rating: ");
    scanf("%d", &rating2);
    printf("Enter the third rating: ");
    scanf("%d", &rating3);

    // Find the average of the best two ratings
    int average;
    if (rating1 > rating2 && rating1 > rating3)
    {
        if (rating2 > rating3)
        {
            average = (rating1 + rating2) / 2;
        }
        else
        {
            average = (rating1 + rating3) / 2;
        }
    }
    else if (rating2 > rating1 && rating2 > rating3)
    {
        if (rating1 > rating3)
        {
            average = (rating1 + rating2) / 2;
        }
        else
        {
            average = (rating2 + rating3) / 2;
        }
    }
    else
    {
        if (rating2 > rating1)
        {
            average = (rating3 + rating2) / 2;
        }
        else
        {
            average = (rating3 + rating1) / 2;
        }
    }

    // Print the result
    printf("The average of the best two ratings is: %d\n", average);

    return 0;
}