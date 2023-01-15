#include <stdio.h>
#include <stdlib.h>
struct node{
	struct node* prev;
	int value;
	struct node* next;
};
struct node* head=NULL;
void printList(struct node* temp){
	if(head == NULL){
    	printf("Empty list");
	}
	else{
    	while(temp!=NULL){
        	printf("%d-",temp->value);
        	temp=temp->next;
    	}
	}
}
struct node* createnode(int value){
	struct node* newnode = malloc(sizeof(struct node));
	newnode->prev = NULL;
	newnode->next = NULL;
	newnode->value = value;
	return newnode;
}
void insert_at_beginning(int value){
	struct node *newnode = createnode(value);
	if(head == NULL){
    	head = newnode;
	}
	else{
    	newnode->next = head;
    	newnode->value = value;
    	head = newnode;
	}
}
void insert_at_last(int value){
	struct node *newnode = createnode(value);
	struct node *temp = head;
	if(head == NULL){
    	head = newnode;
	}
	else{
    	while(temp->next != NULL)
        	temp = temp->next;
    	temp->next = newnode;
    	newnode->prev= temp;
	}
}
int insert_at_specific_position(int value,int search_elem){
	struct node *newnode = createnode(value);
	struct node *temp=head;
	if(head == NULL){
    	head = newnode;
	}
	else{
    	while(temp->value!=search_elem){
        	if(temp->next==NULL){
            	printf("\nelement not found\n");
            	return 0;
        	}
        	temp=temp->next;
    	}
    	newnode->prev = temp;
    	newnode->next = temp->next;
    	temp->next->prev = newnode;
    	temp->next = newnode;  
	}
}
void delete_at_begining(){
	if(head == NULL){
    	printf("Empty list");
	}
	else{
    	head = head->next;
	}
}
void delete_at_specific_position(int search_elem){
	if(head == NULL){
    	printf("Empty list");
	}
	else{
    	struct node *temp = head;
    	struct node* ptr;
    	while(temp->next->value != search_elem){
        	temp = temp->next;
    	}
    	ptr = temp->next;
    	temp->next = ptr->next;
    	ptr->next->prev = temp;
    	free(ptr);
	}
}
void delete_at_end(){
	if(head==NULL){
    	printf("empty list");
	}
	else{
    	struct node *temp,*ptr;
    	temp = head;
    	while(temp->next->next != NULL){
        	temp=temp->next;
    	}
    	ptr = temp->next;
    	temp = temp->next = NULL;
    	free(ptr);
	}
}
int main(){
    

    
	insert_at_beginning(4);
	insert_at_beginning(3);
	insert_at_last(8);
	insert_at_last(9);
	insert_at_specific_position(6,4);
    
	delete_at_end();
	delete_at_begining();
	delete_at_specific_position(6);
    
	printList(head);
}
