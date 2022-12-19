#include <stdio.h>
int front=-1,rear=-1,arr[10];
void enqueue(int value){
    if(rear == sizeof(arr)/4)
        printf("queue overflow");
    else if(rear == -1){
        front = rear = 0;
        arr[rear] = value;
    }
    else
        arr[++rear] = value; 
}
void dequeue(){
    if(front==-1 || front > rear)
        printf("queue underflow");
    else if(front>rear){
        printf("dequeued element: %d",arr[front++]);
        rear = front = -1;
    }
    else{
        printf("dequeued element: %d",arr[front++]);
    }
}
void display(){
    if(rear == -1)
        printf("empty array");
    else{
        int i;
        for(i=front;i<=rear;i++)
            printf("%d ",arr[i]);    
    }
}
void frontElem(){
    if(rear == -1 || front>rear)
        printf("empty queue");
    else
        printf("element ar front: %d",arr[front]);
}
int main(){
    while(1){
        int choice;
        printf("\nChoose an option:\n"
        "1:enqueue()  "
        "2:dequeue()\n"
        "3:frontElem  "
        "4:display\n"
        );
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                printf("Enter a value to insert:");
                int value;
                scanf("%d",&value);
                enqueue(value);
            }
            break;
            case 2: dequeue();
            break;
            case 3:frontElem();
            break;
            case 4:display();
            break;
            default:{
                printf("Exit!");
                return 0;
                
            }
        }
    }    
}
