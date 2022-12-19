#include <stdio.h>
int top=-1,arr[10];
void push(int value){
    if(top == sizeof(arr)/4){
        printf("stack overflow\n");
    }
    else
        arr[++top] = value;
}
int pop(){
    if(top == -1){
        printf("stack underflow\n");
    }
    else{
        printf("%d just got popped\n",arr[top]);
        return top--;
    }
    
}
void display(){
    if(top == -1){
        printf("empty stack\n");
    }
    else{
        int i;
        printf("stack elements are: ");
        for(i=top;i>-1;i--)
            printf("%d ",arr[i]);
        printf("\n");
    }
}
void topElem(){
     if(top == -1){
        printf("empty stack\n");
    }
    else
        printf("top element: %d\n",arr[top]);
}
int main(){
    while(1){
        int choice;
        printf("Choose an option:\n"
        "1:push()  "
        "2:pop()\n"
        "3:topElem  "
        "4:display\n"
        );
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                printf("Enter a value to push:");
                int value;
                scanf("%d",&value);
                push(value);
            }
            break;
            case 2: pop();
            break;
            case 3:topElem();
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