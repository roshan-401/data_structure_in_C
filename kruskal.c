#include <stdio.h>
#define V 6
int parent[6];
int ne=1;
int a,b,u,v;
int mincost = 0;
int find(int i){
  while(parent[i]){
    i = parent[i];
  }
  return i;
}
int uni(int i,int j){
  if(i!=j){
    parent[j] = i;
    return 1;
  }
  return 0;
}
int main(){
    int graph[V][V] = {
        {0,3,1,6,0,0},
        {3,0,5,0,3,0},
        {1,5,0,5,6,4},
        {6,0,5,0,0,2},
        {0,3,6,0,0,6},
        {0,0,4,2,6,0}
    };

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(graph[i][j] == 0)
                graph[i][j] = 999;
            printf("%d\t",graph[i][j]);
        }
        printf("\n");
    }
    while(ne<V){
      int min = 999;
      for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
          if(graph[i][j] < min){
            min = graph[i][j];
            a = u = i;
            b = v = j;
          }
        }
      }
      u = find(u);
      v = find(v);
      if(uni(u,v)){
        printf("%d edge %d-%d = %d\n",ne++,a,b,min);
        mincost += min;
      }
      graph[a][b] = graph[b][a] = 999;
    }
  printf("\n\tmincost = %d\n",mincost);
}

