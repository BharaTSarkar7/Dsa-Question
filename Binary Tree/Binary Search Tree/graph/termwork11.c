#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 100
#define MAX_VERTICES 50

struct edge
{
    int src;
    int dest;
    int weight;
};

struct subset
{
    int parent;
    int rank;
};

int find(struct subset subsets[], int i)
{
    if (subsets[i].parent != i)
    {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

void Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
    {
        subsets[xroot].parent = yroot;
    }
    else if (subsets[xroot].rank > subsets[yroot].rank)
    {
        subsets[yroot].parent = xroot;
    }
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int cmp(const void *a, const void *b)
{
    struct edge *aa = (struct edge *)a;
    struct edge *bb = (struct edge *)b;
    return aa->weight - bb->weight;
}

void Kurskal(struct edge edges[], int numVertices, int numEdges)
{
    int e = 0;
    int i = 0;
    struct edge result[MAX_VERTICES];
    qsort(edges, numEdges, sizeof(edges[0]), cmp);

    struct subset subsets[numVertices];
    for (int v = 0; v < numVertices; v++)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < numVertices - 1)
    {
        struct edge nextEdge = edges[i++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        if (x != y)
        {
            result[e++] = nextEdge;
            Union(subsets, x, y);
        }
    }

    printf("Following are the edges in the constructed MST\n");
    for (i = 0; i < e; ++i)
    {
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
    }
}

int main()
{
    int numVertices = 4;
    int numEdges = 5;
    struct edge edges[MAX_EDGES] = {{0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}};

    Kurskal(edges, numVertices, numEdges);

    return 0;
}
