#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node* next;
};

void main(){
    struct node* head =NULL;
    int choice = 1,count =0 ;

    while(choice){
        struct node* new = (struct node*)malloc(sizeof(struct node));
        struct node* ptr = head;
        printf("Enter element in new node: ");
        scanf("%d",&new->info);
        

        if(head == NULL){
            head = new;
            head ->next = NULL;
        }
        else{
            while(ptr->next!=NULL){
                ptr = ptr->next;
            }
            ptr ->next = new;
            new ->next = NULL;
        }

        printf("Do you want to continue(1/0): ");
        scanf("%d",&choice);
    }

    // Counting node

    struct node *ptr = head;
    while(ptr != NULL){
        count++;
        ptr = ptr->next;
    }

    if(count!=0){
        printf("Number of nodes are: %d\n",count);
    }
    else{
        printf("Linked List is empty\n");
    }

}