#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int table[SIZE];

void init() {
    for(int i = 0; i < SIZE; i++)
        table[i] = -1;
}

int hash(int key) {
    return key % SIZE;
}

void insert(int key) {
    int i = 0;
    int index;
    while(i < SIZE) {
        index = (hash(key) + i * i) % SIZE;
        if(table[index] == -1) {
            table[index] = key;
            return;
        }
        i++;
    }
    printf("Hash table full\n");
}

void display() {
    for(int i = 0; i < SIZE; i++) {
        printf("%d: %d\n", i, table[i]);
    }
}

int main() {
    init();
    insert(10);
    insert(20);
    insert(5);
    insert(15);
    insert(7);
    display();
    return 0;
}