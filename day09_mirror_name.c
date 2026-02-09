// Problem: A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.

#include <stdio.h>
#include <string.h>

int main(){

    char s[100];
    char mirror[100];
    printf("Enter the code name: ");
    gets(s); 

    int l = strlen(s);
    printf("Length of the code name: %d\n", l); 
    int k = l-1;

    for(int i = 0; i<l; i++){
        mirror[k--] = s[i]; 
    }
    
    mirror[l] = '\0';
    printf("Mirror code name: ");
    puts(mirror);
    return 0;
}