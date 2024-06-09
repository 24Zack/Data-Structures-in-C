#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
//recursive stuff
void fun(struct Node * walker)
{
    if(walker ==NULL)
    {
        return;
    }else
    {
        
        fun(walker->next);
        printf("%d\n",walker->data);
    }
}
int main() {
    // Creating nodes
    struct Node* head = createNode(20);
    head->next = createNode(70);
    head->next->next = createNode(0);
    head->next->next->next = createNode(100);

    // Printing the linked list
    struct Node *walker=head;
    fun(walker);
    return 0;
}