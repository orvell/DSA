#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void merge(int arr[], int l, int k, int u){

    int i=l,j=k+1;
    int a=0;
    int temp[j];

    while(i<=k && j<=u){
        if(arr[i]<arr[j])
            temp[a++]=arr[i++];
        else
            temp[a++]=arr[j++];
    }

    while(i<=k)
        temp[a++]=arr[i++];

    while(j<=u)
        temp[a++]=arr[j++];

    for(i=l,j=0;i<=u;i++,j++)
        arr[i]=temp[j];

}


void mergesort(int arr[],int l, int u){

    if(l<u){
        int k=(l+u)/2;

        mergesort(arr,l,k);
        mergesort(arr,k+1,u);

        merge(arr,l,k,u);

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

    mergesort(arr,0,n-1);

    puts("Sorted array : \n");
    for(i=0;i<n;i++)
        printf("%d \t",arr[i]);
}