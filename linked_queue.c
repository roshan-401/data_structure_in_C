#include <stdio.h>
#include <stdlib.h>
struct node{
    int value;
    struct node *next;
};
struct node *front=NULL, *rear=NULL;

struct node* createNode(int value){
    struct node *temp = malloc(sizeof(struct node));
    temp->value = value;
    temp->next = NULL;
}

void enqueue(int value){
    struct node *newnode = createNode(value);
    if(front == NULL)
        front = rear = newnode;
    else{
        rear->next = newnode;
        rear = newnode;
    }
}
void dequeue(){
    if(front == NULL) printf("queue underflow");
    else{
        struct node *temp = front;
        front = front->next;
        free(temp);
    }
}
void display(){
    struct node *temp = front;
    while(temp!=NULL){
        printf("%d-",temp->value);
        temp = temp->next;
    }
}
int main(){
    enqueue(6);
    enqueue(9);
    enqueue(7);
    display();
    dequeue();
    printf("\nafter dequeue\n");
    display();
}