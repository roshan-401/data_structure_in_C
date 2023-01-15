#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node* next;
};
struct node* last = NULL;
struct node* createNode(int value){
    struct node* temp = malloc(sizeof(struct node));
    temp->value = value;
    temp->next = NULL;
    return temp;
}
void insert_at_begining(int value){
    if(last == NULL){
        last = createNode(value);
        last->next = last;
        return;
    }
    struct node* temp = createNode(value);
    temp->next = last->next;
    last->next = temp;
}
void insert_at_end(int value){
    if(last == NULL){
        last = createNode(value);
        return;
    }
    struct node *temp = createNode(value);
    temp->next = last->next;
    last->next = temp;
    last = temp;
}
void printList(){
    struct node *temp = last->next;
    do{
        printf("%d",temp->value);
        temp = temp->next;
    }while(temp!=last->next);
}
int main(){
    insert_at_end(4);
    insert_at_end(5);
    insert_at_end(6);
    printList();
}