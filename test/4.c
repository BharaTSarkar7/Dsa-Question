#include <stdio.h>
#include <ctype.h>

int main()
{
    // Declare a variable to store the color code
    char color_code;

    // Prompt the user to enter the color code
    printf("Enter the color code in (VIBGYOR): ");
    scanf("%c", &color_code); // Note the space before the %c format specifier to skip leading whitespace
    if (islower(color_code) != 0)
    {
        color_code = toupper(color_code);
    }

    // Check the color code and display whether it is a primary or secondary color
    switch (color_code)
    {
    case 'R':
    case 'G':
    case 'B':
        printf("The %c color is a primary color.\n", color_code);
        break;
    default:
        printf("The %c color is a secondary color.\n", color_code);
    }

    return 0;
}
