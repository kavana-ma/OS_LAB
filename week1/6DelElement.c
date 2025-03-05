//Write a program in C to delete an element at a desired position from an array.

#include<stdio.h>
#define SIZE 5

int delete(int arr[],int n,int pos){
    int res=arr[pos-1];
    for(int i=pos-1;i<n-1;i++){
            arr[i]=arr[i+1];
    }
    arr[n-1]=-1;//last postion empty
    return res;
}

void main(){
    int arr[SIZE],pos;
    printf("Enter elements for array: \n");
    for(int i=0;i<SIZE;i++){
        scanf("%d",&arr[i]);
    }
    printf("\nEnter position: ");
    scanf("%d",&pos);
    int result=delete(arr,SIZE,pos);
    printf("Deleted %d at position %d. ",result,pos);

    printf("\nArray after deletion:\n");
    for(int i=0;i<SIZE;i++){
        printf("%d ",arr[i]);
    }
}
