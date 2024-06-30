#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int vertex;
    int weight;
    struct node* next;
}GNode;

typedef struct{
    int v;
    int e;
    GNode** Adjlist;
}Graph;

GNode* createNode(int v, int w){
    GNode* newNode = (GNode*)malloc(sizeof(GNode));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int vertices){
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->v = vertices;
    graph->e = 0;

    graph->Adjlist = (GNode**)malloc(vertices*sizeof(GNode*));

    for (int i = 0; i < vertices; i++)
    {
        graph->Adjlist[i] = NULL;
    }
    return graph;

}

void addEdge(Graph* graph, int src, int dest, int weight){
    GNode* newNode = createNode(dest, weight);
    newNode->next = graph->Adjlist[src];
    graph->Adjlist[src] = newNode;
    graph->e++;
}

void removeEdge(Graph* graph, int src, int dest){
    GNode* current = graph->Adjlist[src];
    GNode* prev = NULL;
while (current->vertex != dest || current != NULL)
    {
        prev = current;
        current = current->next;
    }



    if (current != NULL)
    {
        if (prev == NULL)
        {
            graph->Adjlist[src]=current->next;
            free(current);
        }
        else
        {
             prev->next = current->next;
             free(current);
        }
    }
    else
    {
        printf("The edge was not found! \n");
    }
    graph->e--;



}

int AdjacentEdge(Graph* graph, int src, int dest){
    GNode* current = graph->Adjlist[src];
while (current != NULL)
    {
        if (current->vertex == dest)
        {
            return 1;
        }
        else
        {
            current = current->next;
        }

    }
    return 0;
}

int outdeg(Graph* graph, int src){
        GNode* current = graph->Adjlist[src];
        int counter = 0;
while (current != NULL)
    {

     current = current->next;
     counter++;

    }

return counter;
}

void printGraph(Graph* graph){
    for (int i = 0; i < graph->v; i++)
    {
        GNode* current = graph->Adjlist[i];
        printf("Adjacency list of vertex %d is: ", i);
        while (current)
        {
            printf(" (%d, %d) -> ", current->vertex, current->weight);
            current = current->next;
        }
        printf("NULL\n");

    }

}

void bfs(Graph *graph, int startVertex)
{
    int visited[graph->v];
    for (int i = 0; i < graph->v; i++)
    {
        visited[i] = 0;
    }

    int queue[graph->v];
    int front = 0, rear = 0;

    visited[startVertex] = 1;
    queue[rear] = startVertex;
    rear = (rear + 1) % graph->v;

    while (front != rear)
    {
        int currentVertex = queue[front];
        front = (front + 1) % graph->v;
        printf("%d ", currentVertex);

        GNode* temp = graph->Adjlist[currentVertex];
        while (temp != NULL)
        {
            int neighbor = temp->vertex;
            if (!visited[neighbor])
            {
                visited[neighbor] = 1;
                queue[rear] = neighbor;
                rear = (rear + 1) % graph->v;
            }
            temp = temp->next;
        }

    }
    printf("\n");
}

void dfs(Graph *graph, int startVertex, int visited[]){
    GNode *temp = graph->Adjlist[startVertex];

    visited[startVertex] = 1;
    printf("%d ", startVertex);

    while (temp != NULL)
    {
        int adjVertex = temp->vertex;
        if (visited[adjVertex] == 0)
        {
            dfs(graph, adjVertex, visited);
        }
        temp = temp->next;
    }

}

int minDistance(int d[], int c[], int v){
    int min;
}
