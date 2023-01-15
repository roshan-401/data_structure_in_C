#include <stdio.h>
#include <stdlib.h>
struct node{
	int value;
	struct node* next;
};
struct node *n1,*n2,*n3,*head=NULL;
struct node* createNode(int value){
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->value = value;
	newnode->next = NULL;
	return newnode;
}
void printList(struct node *head){
	struct node* temp = head;
	if(head == NULL){
    	printf("list empty");
	}
	else{
    	while(temp!=NULL){
        	printf("%d-",temp->value);
        	temp=temp->next;
    	}
	}
}
void insert_at_first(int value){
	struct node *temp = createNode(value);
	temp->next = head;
	head = temp;
}
void insert_at_last(int value){
	struct node *temp = createNode(value);
	if(head == NULL) head = temp;
	else {
    	struct node *pointer = head;
    	while(pointer->next != NULL){
        	pointer = pointer->next;
    	}
    	pointer->next = temp;
	}
}
int insert_at_specific_position(int value,int search_elem){
	struct node *temp = createNode(value);
	struct node *pointer = head;
	while(pointer->value != search_elem){
    	if(pointer->next == NULL)
        	return 0;
    	pointer = pointer->next;
	}
	temp->next = pointer->next;
	pointer->next = temp;
}
void delete_at_beginning(){
	if(head == NULL)
    	printf("empty list");
	else if(head->next==NULL)
    	head = NULL;
	else{
    	struct node* temp = head;
    	head = head->next;
    	free(temp);
	}
}
void delete_at_last(){
	if(head == NULL)
    	printf("empty list");
	else if(head->next==NULL)
    	head = NULL;
	else{
    	struct node* pointer = head;
    	while(pointer->next->next!=NULL){
        	// printf("%d-",pointer->value);
        	pointer = pointer->next;
    	}
    	struct node* temp = pointer->next;
    	pointer->next = NULL;
    	free(temp);
	}
}
void delete_at_specific_position(int search_elem){
	struct node *temp = head;
	while(temp->next->value!=search_elem){
    	temp = temp->next;
	}
	temp->next = temp->next->next;
}

void main(){
    
	
    
	insert_at_first(23);
	insert_at_first(33);
	insert_at_last(76);
	insert_at_last(89);
	insert_at_last(99);
	// delete_at_specific_position(76);
	insert_at_specific_position(4,75);
	// delete_at_beginning();
	delete_at_last();
	delete_at_last();
	delete_at_last();
	delete_at_last();

    
	printList(head);


}


