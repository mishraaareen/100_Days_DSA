#include <stdio.h>
#define MAX 5   // Maximum size of stack

int stack[MAX];
int top = -1;

// Push Operation
void push(int value)
{
    if (top == MAX - 1)
    {
        printf("\nStack Overflow!");
    }
    else
    {
        top++;
        stack[top] = value;
        printf("\n%d pushed into stack.", value);
    }
}

// Pop Operation
void pop()
{
    if (top == -1)
    {
        printf("\nStack Underflow!");
    }
    else
    {
        printf("\n%d popped from stack.", stack[top]);
        top--;
    }
}

// Display Operation
void display()
{
    if (top == -1)
    {
        printf("\nStack is Empty!");
    }
    else
    {
        printf("\nStack elements are:\n");
        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

// Main Function
int main()
{
    int choice, value;

    while (1)
    {
        printf("\n\n--- STACK MENU ---");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice!");
        }
    }
}