// Problem: Read a string and check if it is a palindrome using two-pointer comparison.

#include <stdio.h>
#include <string.h>

int main(){

    char str[100];
    printf("Enter a string: ");
    gets(str);

    int size = strlen(str);
    int left = 0;
    int right = size - 1;
    
    int is_palindrome = 1;

    while(left < right){
        if(str[left] != str[right]){
            is_palindrome = 0;
            break;
        }
        left++;
        right--;
    }

    if(is_palindrome){
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}