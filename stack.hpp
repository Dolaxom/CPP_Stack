#include <stdlib.h>
#include <string.h>

#define STACK_TYPE const void *

enum
{
    OK,
    ERROR
};

typedef struct Stack
{
    void *data;
    struct Stack *next;
} Stack;

int push(Stack **stack, STACK_TYPE data, unsigned int type_size);
int pop(Stack **stack);
int peek(Stack *stack);
int size(Stack *stack);
void remove_stack(Stack **stack);

int push(Stack **stack, STACK_TYPE data, unsigned int type_size)
{
    Stack *temp = (Stack *)malloc(sizeof(Stack));
    if (temp == NULL)
        return ERROR;

    temp->data = malloc(type_size);
    if (temp->data == NULL)
        return ERROR;

    memcpy(temp->data, data, type_size);
    temp->next = (*stack);
    (*stack) = temp;

    return OK;
}

int pop(Stack **stack)
{
    Stack *previous = NULL;
    if (stack == NULL)
        return ERROR;

    previous = (*stack);
    (*stack) = (*stack)->next;

    free(previous->data);
    free(previous);

    return OK;
}

int peek(Stack *stack)
{
    return *(int *)stack->data;
}

int size(Stack *stack)
{
    Stack *temp = stack;
    int size = 0;
    while (temp != NULL)
    {
        ++size;
        temp = temp->next;
    }
    return size;
}

void remove_stack(Stack **stack)
{
    while ((*stack)->next != NULL)
    {
        pop(stack);
        *stack = (*stack)->next;
    }
    free((*stack)->data);
    free(*stack);
    *stack = NULL;
}
