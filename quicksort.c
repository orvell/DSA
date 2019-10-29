#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int partition(int arr[],int l,int u){

  int pivot=arr[u];
  int i=l-1;
  int j;
  for(j=l;j<u;j++){
    if(arr[j]<pivot){
      i++;
      //swap(arr[i],arr[j]);
       int tmp=arr[j];
       arr[j]=arr[i];
       arr[i]=tmp;
     }
  }
   //swap(arr[i+1],arr[size]);
       int tmp=arr[i+1];
       arr[i+1]=arr[u];
       arr[u]=tmp;
  return (i+1);
}


void quicksort(int arr[],int l, int u){

    if(l<u){
        int j = partition(arr,l,u);

        quicksort(arr,l,j-1);
        quicksort(arr,j+1,u);

    }

}

void main(){

    int n,i;
    puts("Enter no of elements");
    scanf("%d",&n);
    int arr[n];

    puts("Enter data");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    quicksort(arr,0,n);

    puts("Sorted array : \n");
    for(i=0;i<n;i++)
        printf("%d \t",arr[i]);
}