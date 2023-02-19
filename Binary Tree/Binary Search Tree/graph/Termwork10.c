#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

struct edge
{
    int dest;
    struct edge *next;
};

struct vertex
{
    int data;
    struct edge *edges;
    int visited;
};

struct graph
{
    struct vertex *vertices[MAX_VERTICES];
    int numVertices;
};

struct edge *createEdge(int dest)
{
    struct edge *newEdge = (struct edge *)malloc(sizeof(struct edge));
    newEdge->dest = dest;
    newEdge->next = NULL;
    return newEdge;
}

struct vertex *createVertex(int data)
{
    struct vertex *newVertex = (struct vertex *)malloc(sizeof(struct vertex));
    newVertex->data = data;
    newVertex->edges = NULL;
    newVertex->visited = 0;
    return newVertex;
}

void addEdge(struct graph *g, int src, int dest)
{
    struct edge *newEdge = createEdge(dest);
    newEdge->next = g->vertices[src]->edges;
    g->vertices[src]->edges = newEdge;
}

void DFS(struct graph *g, int start)
{
    g->vertices[start]->visited = 1;
    printf("%d ", g->vertices[start]->data);

    struct edge *current = g->vertices[start]->edges;
    while (current != NULL)
    {
        int next = current->dest;
        if (!g->vertices[next]->visited)
        {
            DFS(g, next);
        }
        current = current->next;
    }
}

int main()
{
    struct graph g;
    g.numVertices = 4;

    for (int i = 0; i < g.numVertices; i++)
    {
        g.vertices[i] = createVertex(i);
    }

    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 2);
    addEdge(&g, 2, 0);
    addEdge(&g, 2, 3);
    addEdge(&g, 3, 3);

    printf("DFS traversal: ");
    DFS(&g, 2);
    printf("\n");

    return 0;
}

/*This program defines three structs: edge, vertex, and graph. The edge struct represents an edge in the graph, with fields for the destination vertex and a pointer to the next edge. The vertex struct represents a vertex in the graph, with a field for the data, a field to track whether the vertex has been visited during the search, and a pointer to the first edge in a linked list of edges. The graph struct represents the graph itself, with an array of pointers to the vertices and a field for the number of vertices.

The createEdge and createVertex functions are used to create new edges and vertices, respectively. They allocate memory for the new edge or vertex and initialize the fields*/