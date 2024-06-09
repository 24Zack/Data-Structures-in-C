#include <stdio.h>
#define MAX 10
/*
#define N 10

typedef struct node{
    int data;
    struct node* adjacent[(N*(N-1))/2];
}Node;
*/

int graph[MAX][MAX], visited[MAX];
int num_verticies;

int stack[MAX];
int top = -1;

void push(int v) {
    if (top >= MAX - 1) {
        printf("Stack overflow\n");
    } else {
        stack[++top] = v;
    }
}


int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

void dfs(int v){
    push(v);

    while(top != -1){
        v = pop();
        if(!visited[v]) {
            printf("%d", v);
            visited[v] = 1;

            for(int w = 0; w < num_verticies; w++) {
                if(graph[v][w] && !visited[w]) {
                    push(w);
                }
            }
        }
    }
}