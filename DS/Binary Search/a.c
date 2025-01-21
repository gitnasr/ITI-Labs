#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STACK_SIZE 1000

typedef struct
{
    char data[MAX_STACK_SIZE];
    int top;
} Stack;

bool isEmpty(Stack *stack)
{
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(Stack *stack, char ch)
{
    if (stack->top < MAX_STACK_SIZE - 1)
    {
        stack->data[++stack->top] = ch;
    }
}

// Function to pop an element from the stack
char pop(Stack *stack)
{
    if (!isEmpty(stack))
    {
        return stack->data[stack->top--];
    }
    return '\0'; // Return null character if stack is empty
}

int main()
{
    char *input = "(){}";
    Stack myStack;
    myStack.top = -1; // Initialize stack
    int isBalanced = 1;
    char firstElementAtStack;

    for (int i = 0; input[i] != '\0'; i++)
    {
        char p = input[i];
        if (p == '(' || p == '{' || p == '[')
        {
            push(&myStack, p);
        }
        else
        {
            if (!isEmpty(&myStack))
            {
                firstElementAtStack = pop(&myStack);
                if ((p == ')' && firstElementAtStack == '(') ||
                    (p == '}' && firstElementAtStack == '{') ||
                    (p == ']' && firstElementAtStack == '['))
                {
                    isBalanced = 1;
                }
                else
                {
                    isBalanced = 0;
                    break;
                }
            }
            else
            {
                isBalanced = 0;
                break;
            }
        }
    }

    if (!isEmpty(&myStack))
    {
        isBalanced = 0;
    }

    printf("is Balanced: %d\n", isBalanced);
    return 0;
}
