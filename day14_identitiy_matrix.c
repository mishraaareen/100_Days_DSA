#include <stdio.h>

int main(){

    int n,count_1 = 0,count_0 = 0;

    printf("Enter row and column of a square matrix: ");
    scanf("%d",&n);
    int arr[n][n];

    printf("Enter element in matrix: ");
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            scanf("%d",&arr[i][j]);
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){

            if(i==j && arr[i][j]==1)
                count_1++;
            else{
                if(arr[i][j] == 0)
                    count_0++;
            }
        }
    }

    if(count_1 == n && count_0 == (n*n - n))
        printf("Identity matrix");
    else
        printf("Not an identity matrix");

    return 0;
}