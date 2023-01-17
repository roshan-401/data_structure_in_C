#include<stdio.h>
int queue[100];

// int front=-1,rear=-1;

// void enq(int var)
// {
//     q[rear] = var;
//     rear++;
// }

// void dq()
// {
//     q[front] = 0;
//     front++;
// }
// int visited[6] = {0};

// int main()
// {

//    int graph[6][6] = {
//        //1 2 3 4 5 6 
//   /*1*/ {0,0,0,0,1,1},
//   /*2*/ {0,0,0,0,0,1},
//   /*3*/ {0,0,0,1,1,1},
//   /*4*/ {0,0,1,0,1,0},
//   /*5*/ {1,0,1,1,0,0},
//   /*6*/ {1,1,1,0,0,0}
//     };


//     enq(1);
//     visited[0] = 1;
//     while(front != rear)
//     {
//         int current = q[front];

//         printf("%d ", current);
//         dq();

//         for(int i=0;i<6;i++)
//         {

//             if((graph[current-1][i] == 1) && (visited[i] == 0))
//             {
//                 visited[i] = 1;
//                 enq(i+1);
//             }
//         }
//     }
//     return 0;
// }


   int graph[6][6] = {
       //1 2 3 4 5 6 
  /*1*/ {0,0,0,0,1,1},
  /*2*/ {0,0,0,0,0,1},
  /*3*/ {0,0,0,1,1,1},
  /*4*/ {0,0,1,0,1,0},
  /*5*/ {1,0,1,1,0,0},
  /*6*/ {1,1,1,0,0,0}
    };

int main(){
    int front = 0;
    int rear = 0;
    int visited[6];

    //setting the source
    queue[rear] = 0;
    visited[0] = 1;

    while(front<=rear){
        int source = queue[front++]; 
        printf("%d ",source);

        for(int i=0;i<6;i++){
            if(graph[source][i] == 1 && visited[i]!=1){
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }

}