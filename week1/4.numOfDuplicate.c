// Write a program in C to count the total number of duplicate elements in an array.

#include<stdio.h>
#define SIZE 5

int numOfDuplicates(int arr[], int n) {
    int count = 0;
    int visited[SIZE] = {0}; 

    for(int i = 0; i < n; i++) {
        if(visited[i] == 1) {
            continue; 
        }
        for(int j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                visited[j] = 1; 
                count++;
                break;
            }
        }
    }
    return count;
}

int main() {
    int arr[SIZE]; 
    printf("Enter elements for array: \n");
    for(int i=0;i<SIZE;i++){
        scanf("%d",&arr[i]);
    }
    int duplicateCount = numOfDuplicates(arr, SIZE);
    printf("Total number of duplicate elements: %d\n", duplicateCount);
    return 0;
}
