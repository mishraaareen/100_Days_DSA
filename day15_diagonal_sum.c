#include <stdio.h>

int main(){

    int r,c,sum = 0;
    printf("Enter no. of rows and column: ");
    scanf("%d%d",&r,&c);

    int arr[r][c];

    printf("Enter element in an array: ");
    for(int i = 0; i<r;i++){
        for(int j = 0; j <c; j++){
            scanf("%d",&arr[i][j]);
        }
    }

    for(int i = 0; i<r;i++){
        for(int j = 0; j < c; j++){
            if(i==j)
                sum += arr[i][j];
        }
    }

    printf("%d\n",sum);


    return 0;
}