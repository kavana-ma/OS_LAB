//Write a program in C to find the second-smallest element in an array.

#include<stdio.h>
#define SIZE 5

int sort(int arr[],int n){
    int i,j;
    printf("Before sorting: \n");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                int temp= arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    printf("\nAfter sorting: \n");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    return arr[1];
}

void main(){
    int arr[SIZE];
    printf("Enter elements for array: \n");
    for(int i=0;i<SIZE;i++){
        scanf("%d",&arr[i]);
    }
    int result=sort(arr,SIZE);
    printf("\n2nd smallest element is : %d ",result);
}
