#include <stdio.h>
#include <stdlib.h>
int main()
{
    void **head = NULL, **temp = NULL;
    int c = 0;
    do
    {
        if (head == NULL)
        {
            temp = head = (void *)calloc(2, sizeof(void *));
            head[1] = NULL;
        }
        else
        {
            temp[1] = (void *)calloc(2, sizeof(void *));
            temp = temp[1];
            // temp[]
        }
        temp[0] = (int *)malloc(sizeof(int));
        printf("\nenter an int element: ");
        scanf("%d", (int *)temp[0]);
        printf("\ndo you want to enter more data (0/1): ");
        scanf("%d", &c);
    } while (c);
    temp[1] = NULL;
    printf("\n");
    for (temp = head; temp != NULL; temp = temp[1])
        printf("%d\n", ((int)(temp[0])));
    return 0;
}