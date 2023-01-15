
#include <stdio.h>
#include <stdlib.h>
struct node{
	int value;
	struct node *next;
};
struct node *head=NULL;
struct node* createNode(int value){
	struct node* temp = malloc(sizeof(struct node));
	temp->next = NULL;
	temp->value = value;
	return temp;
}
void printList(struct node* head){
	struct node *temp = head;
	while(temp!=NULL){
    	printf("%d-",temp->value);
    	temp = temp->next;
	}
}
void insert_at_beginning(int value){
	struct node *newnode = createNode(value);
	if(head == NULL){
    	head = newnode;
	}
	else{
    	newnode->next = head;
    	head = newnode;
	}
}
void delete_at_beginning(){
	if(head == NULL)
    	printf("empty list");
	head = head->next;
}
int main()
{   
	insert_at_beginning(7);
	insert_at_beginning(8);
	insert_at_beginning(9);
	delete_at_beginning();
	delete_at_beginning();
	insert_at_beginning(1);
	printList(head);
}

