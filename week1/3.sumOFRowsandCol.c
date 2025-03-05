// Write a program in C to find the sum of rows and columns of a matrix.

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

    printf("\nSum of rows :\n");
    for(int i=0;i<SIZE;i++){
        int sum=0;
        printf("row %d",i+1);
        for(int j=0;j<SIZE;j++){
           sum += mat[i][j];
        }
        printf(": %d",sum);
        printf("\n");
    }

    printf("\nSum of columns :\n");
    for(int i=0;i<SIZE;i++){
        int colsum=0;
        printf("column %d",i+1);
        for(int j=0;j<SIZE;j++){
           colsum += mat[j][i];
        }
        printf(": %d",colsum);
        printf("\n");
    }

}
