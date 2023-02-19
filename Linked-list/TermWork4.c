#include <stdio.h>
#include <stdlib.h>

typedef struct link
{
    int coeff;
    int pow;
    struct link *next;
} polynom;

void my_show_poly(polynom *node)
{
    printf("\nThe polynomial expression is:\n");
    while (node != NULL)
    {
        printf("%dx^%d", node->coeff, node->pow);
        node = node->next;
        if (node != NULL)
            printf(" + ");
    }
}

void my_create_poly(polynom **node)
{
    int flag;
    int coeff, pow;
    polynom *temp_node;
    temp_node = (polynom *)malloc(sizeof(polynom));
    *node = temp_node;
    do
    {
        printf("\nEnter Coeff:");
        scanf("%d", &coeff);
        temp_node->coeff = coeff;
        printf("\nEnter Pow:");
        scanf("%d", &pow);
        temp_node->pow = pow;
        temp_node->next = NULL;
        printf("\nContinue adding more terms to the polynomial list?(Y = 1/N = 0): ");
        scanf("%d", &flag);
        if (flag)
        {
            temp_node->next = (polynom *)malloc(sizeof(polynom)); // Grow the list
            temp_node = temp_node->next;
            temp_node->next = NULL;
        }
    } while (flag);
}

void my_add_poly(polynom **result, polynom *poly1, polynom *poly2)
{
    polynom *temp_node;
    temp_node = (polynom *)malloc(sizeof(polynom));
    temp_node->next = NULL;
    *result = temp_node;
    while (poly1 && poly2)
    {
        if (poly1->pow > poly2->pow)
        {
            temp_node->pow = poly1->pow;
            temp_node->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        else if (poly1->pow < poly2->pow)
        {
            temp_node->pow = poly2->pow;
            temp_node->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        else
        {
            temp_node->pow = poly1->pow;
            temp_node->coeff = poly1->coeff + poly2->coeff;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        if (poly1 && poly2)
        {
            temp_node->next = (polynom *)malloc(sizeof(polynom));
            temp_node = temp_node->next;
            temp_node->next = NULL;
        }
    }
    while (poly1 || poly2)
    {
        temp_node->next = (polynom *)malloc(sizeof(polynom));
        temp_node = temp_node->next;
        temp_node->next = NULL;

        if (poly1)
        {
            temp_node->pow = poly1->pow;
            temp_node->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        if (poly2)
        {
            temp_node->pow = poly2->pow;
            temp_node->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
    }

    printf("\nAddition Complete");
}

int main(void)
{
    int ch;
    do
    {
        polynom *poly1, *poly2, *poly3;

        printf("\nCreate 1st expression\n");
        my_create_poly(&poly1);
        printf("\nStored the 1st expression");
        my_show_poly(poly1);

        printf("\nCreate 2nd expression\n");
        my_create_poly(&poly2);
        printf("\nStored the 2nd expression");
        my_show_poly(poly2);

        my_add_poly(&poly3, poly1, poly2);
        my_show_poly(poly3);

        printf("\nAdd two more expressions? (Y = 1/N = 0): ");
        scanf("%d", &ch);
    } while (ch);
    return 0;
}