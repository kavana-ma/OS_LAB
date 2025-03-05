//Write a program in C to find the sum of the left diagonals of a matrix.

#include<stdio.h>
#define SIZE 3

void main(){
    int mat[SIZE][SIZE];
    printf("\nEnter elements of matrix:\n");
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            scanf("%d",&mat[i][j]);
        }
    }
    printf("\nMatrix:\n");
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }

    int diagonalsum=0;
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if(i==j){
                diagonalsum +=mat[i][j];
            }
        }
    }

    printf("\nDiagonal elements sum: %d", diagonalsum);

}
