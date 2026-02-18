#include <stdio.h>

void reverse(int *nums, int start,int end){

    while(start<end){
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

void rotate(int *nums ,int size,int k){
    if(size==0)
        return;
    k = k%size;

    reverse(nums,0,size-1);
    reverse(nums,0,k-1);
    reverse(nums,k,size-1);
}

int main(){

    int size,k ;
    printf("Enter size of an array: ");
    scanf("%d",&size);

    printf("Enter steps to be rotated: ");
    scanf("%d",&k);

    int nums[size];
    printf("Enter %d element in an array: ",size);
    for(int i = 0; i<size; i++){
        scanf("%d",&nums[i]);
    }

    rotate(nums,size,k);

    printf("Rotated array is: ");
    for(int i = 0; i<size; i++){
        printf("%d ",nums[i]);
    }

    printf("\n");

    

    return 0;
}