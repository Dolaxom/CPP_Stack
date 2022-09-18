#include <iostream>
#include "../stack.hpp"

int main()
{
    Stack *int_stack = NULL;
    int int_value;
    int_value = 5;
    push(&int_stack, (STACK_TYPE)&int_value, sizeof(int));

    int_value = 25;
    push(&int_stack, (STACK_TYPE)&int_value, sizeof(int));
    
    std::cout << "size: " << size(int_stack) << "\n";

    pop(&int_stack);
    std::cout << "size: " << size(int_stack) << "\n";

    int tmp = peek(int_stack);
    std::cout << "peek: " << tmp << "\n";
}
