#include <stdio.h>

struct node
{
    int roll_no;
    struct node *next;
};

int main()
{
    struct node var1, var2, var3;
    var1.roll_no = 24;
    var2.roll_no = 19;
    var3.roll_no = 33;

    var1.next = &var2;
    var2.next = &var3;
    var3.next = NULL;

    printf("n1 = %d\n", var1.roll_no);
    printf("n2 = %d\n", var1.next->roll_no);
    printf("n3 = %d\n", var1.next->next->roll_no);

    struct node *head = &var1;

    while (head != NULL)
    {
        printf("%d\t", head->roll_no);
        head = head->next;
    }

    return 0;
}