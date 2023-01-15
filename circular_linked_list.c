#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node *next;
};
struct node *n1,*n2,*n3,*n4;
struct node *last=NULL;
struct node *createNode(int value){
    struct node *temp = malloc(sizeof(struct node));
    temp->value = value;
    temp->next = NULL;
    return temp;
}
void print_list(struct node *temp){
    while(temp!=last){
        printf("%d-",temp->value);
        temp = temp->next;
    }
    printf("%d",temp->value);
}
void insert_first(int value){
    struct node *temp = createNode(value);
    if(last==NULL){
        last = temp;
        last->next = last;
        return;
    }
    temp->next = last->next;
    last->next = temp;
}
void insert_last(int value){
    struct node *temp = createNode(value);
    if(last == NULL){
        last = temp;
        last->next = last;
        return;
    }
    temp->next = last->next;
    last->next = temp;
    last = temp;
}
void insert_middle(int value,int search_elem){
    struct node *node = createNode(value);
    if(last == NULL){
        printf("empty list\ninserted %d as first element");
        insert_first(value);
        return;
    }
    struct node *temp = last->next;
    while(temp->value!=search_elem){
        if(temp==last){
            printf("element %d is not in this list\n",search_elem);
            return;
        }
        temp = temp->next;
    }
    node->next = temp->next;
    temp->next = node;
}
int main(){
    // n1 = createNode(1);
    // n2 = createNode(2);
    // n3 = createNode(3);
    // n4 = createNode(4);

    // n1->next = n2;
    // n2->next = n3;
    // n3->next = n4;
    // n4->next = n1;
    // last = n4;

    insert_last(5);
    insert_first(0);
    insert_middle(99,3);
    insert_middle(98,7);

    



    print_list(last->next);
}
