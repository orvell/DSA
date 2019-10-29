#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>


void heapify(int arr[],int size,int i){
    int l = (2*i)+1;
    int r =(2*i)+2;
    int largest = i;

    if(l<size && arr[l]>arr[largest])
        largest = l;

    if(r<size && arr[r]>arr[largest])
        largest = r;

    if(largest != i){
      //swap arr[i],arr[largest]
        int temp;
        temp=arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;
      heapify(arr,size,largest);
    }
}


void buildMaxHeap(int arr[],int size){
    int i;
    for(i=size/2 -1;i>=0;i--)
        heapify(arr,size,i);

    for (i=size-1; i>=0; i--){
        //swap(arr[0], arr[i]);
        int temp;
        temp=arr[i];
        arr[i]=arr[0];
        arr[0]=temp;
        heapify(arr,i,0);
    }
}


void main(){
    printf("Enter size of array to sort using heapsort algorithm: \n");
    int size;
    scanf("%d",&size);
    int arr[size];
    int i;
    printf("Enter values \n");

    for(i=0;i<size;i++)
        scanf("%d",&arr[i]);


    buildMaxHeap(arr,size);

    printf("Sorted array is");

    for(i=0;i<size;i++)
        printf("%d \t",arr[i]);
}