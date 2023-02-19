#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to merge two subarrays of strings */
void merge(char **arr, int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    /* Create temp arrays */
    char **L = malloc(n1 * sizeof(char *));
    char **R = malloc(n2 * sizeof(char *));

    /* Copy data to temp arrays L and R */
    for (i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }

    /* Merge the temp arrays back into arr[left..right] */
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (strcmp(L[i], R[j]) <= 0)
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L, if there are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R, if there are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    /* Free the allocated memory */
    free(L);
    free(R);
}

/* Function to sort an array of strings using merge sort */
void merge_sort(char **arr, int left, int right)
{
    if (left < right)
    {
        /* Find the middle point */
        int mid = left + (right - left) / 2;

        /* Sort the first and second halves */
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        /* Merge the sorted strings */
        merge(arr, left, mid, right);
    }
}

int main()
{
    int n;
    printf("\nEnter the number of strings: ");
    scanf("%d", &n);

    /* Allocate memory for the array of strings */
    char **arr = malloc(n * sizeof(char *));

    /* Read the strings from the user */
    printf("\nEnter the strings: \n");
    for (int i = 0; i < n; i++)
    {
        arr[i] = malloc(100 * sizeof(char));
        scanf("%s", arr[i]);
    }

    /* Sort the array of strings using merge sort */
    merge_sort(arr, 0, n - 1);

    /* Print the sorted strings */
    printf("\nSorted strings\n");
    for (int i = 0; i < n; i++)
        printf("%s ", arr[i]);

    return 0;
}

