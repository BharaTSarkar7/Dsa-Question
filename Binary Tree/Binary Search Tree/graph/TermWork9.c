
/*This program defines three structs: edge, vertex, and graph. The edge struct represents an edge in the graph, with fields for the destination vertex and a pointer to the next edge. The vertex struct represents a vertex in the graph, with a field for the data and a pointer to the first edge in a linked list of edges. The graph struct represents the graph itself, with an array of pointers to the vertices and a field for the number of vertices.

The createEdge and createVertex functions are used to create new edges and vertices, respectively. They allocate memory for the new edge or vertex and initialize the fields to the given values.

The addEdge function is used to add a new edge to the graph. It takes a pointer to the graph, the source vertex, and the destination vertex as arguments*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

struct edge
{
    int dest;
    struct edge *next;
};

/* Data structure for representing a vertex in the graph */
struct vertex
{
    int data;
    struct edge *edges;
};

/* Data structure for representing a graph */
struct graph
{
    struct vertex *vertices[MAX_VERTICES];
    int numVertices;
};

/* Function to create an edge to the graph */
struct edge *createEdge(int dest)
{
    struct edge *newEdge = (struct edge *)malloc(sizeof(struct edge));
    newEdge->dest = dest;
    newEdge->next = NULL;
    return newEdge;
}

/* Function to create an vertex to the graph */
struct vertex *createVertex(int data)
{
    struct vertex *newVertex = (struct vertex *)malloc(sizeof(struct vertex));
    newVertex->data = data;
    newVertex->edges = NULL;
    return newVertex;
}

/* Function to add an edge to the graph */
void addEdge(struct graph *g, int src, int dest)
{
    struct edge *newEdge = createEdge(dest);
    newEdge->next = g->vertices[src]->edges;
    g->vertices[src]->edges = newEdge;
}

/* Function to display the graph */
void printGraph(struct graph *g)
{
    for (int i = 0; i < g->numVertices; i++)
    {
        printf("Vertex %d: ", g->vertices[i]->data);
        struct edge *current = g->vertices[i]->edges;
        while (current != NULL)
        {
            printf("%d ", current->dest);
            current = current->next;
        }
        printf("\n");
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

    printGraph(&g);

    return 0;
}