#include <stdio.h>

void merge(int arr[],int start,int mid,int end){
    int p = start, q = mid+1;
    int sortArr[end-start+1],k=0;
    for(int i=start;i<=end;i++){
        if(p > mid)
            sortArr[k++] = arr[q++]; // insert reamining elems
        else if(q > end)
            sortArr[k++] = arr[p++]; // insert reamining elems
        else if(arr[p] < arr[q])
            sortArr[k++] = arr[p++];
        else 
            sortArr[k++] = arr[q++];
    }
    for(int p=0;p<k;p++){
        arr[start++] = sortArr[p];
    }
}
void merge_sort(int arr[],int start,int end){
    if(start<end){
        int mid = (start+end)/2;
        merge_sort(arr,start,mid);
        merge_sort(arr,mid+1,end);
        merge(arr,start,mid,end);
    }
}
void printArr(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d-",arr[i]);
    }
}
int main(){
    int arr[] = {5,4,7,6,2,9,3};
    int size = sizeof(arr)/4;
    merge_sort(arr,0,size-1);
    printArr(arr,size);
}