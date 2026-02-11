// Problem: Write a program to perform addition of two matrices having the same dimensions. The sum of two matrices is obtained by adding corresponding elements of the matrices.

#include <stdio.h>
void add_matrix(int r,int c, int arr1[r][c], int arr2[r][c]);

void add_matrix(int r, int c, int arr1[r][c], int arr2[r][c]){

    int sum[r][c];

    for(int i = 0; i<r; i++){

        for(int j = 0; j<c; j++){
            sum[i][j] = arr1[i][j] + arr2[i][j];
        }
    }

    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            printf("%d ",sum[i][j]);
        }
        printf("\n");
    }

}

int main(){

    int r,c;
    printf("Enetr row and  column of matrix: ");
    scanf("%d%d",&r,&c);

    int arr1[r][c],arr2[r][c];

    printf("Enter element in 1st matrix: ");
    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            scanf("%d",&arr1[i][j]);
        }
    }

    printf("Enter element in 2nd matrix: ");
    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            scanf("%d",&arr2[i][j]);
        }
    }

    add_matrix(r,c,arr1,arr2);


    return 0;
}
