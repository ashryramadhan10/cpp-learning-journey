#include <iostream>
const unsigned int MAX_STACK_SIZE = 10;

template <class Type> class Stack {
    private:
        Type data;
        Stack<Type>* next;
        Stack<Type>* prev;
    public:
        static Stack<Type>* top;
        static unsigned int length;

        Stack();
        ~Stack();
        void push(Type data);
        Type pop();
        void clear();
};

template <class Type>
Stack<Type>* Stack<Type>::top = {nullptr};

template <class Type>
unsigned int Stack<Type>::length = 0;

template <class Type> 
Stack<Type>::Stack(): next(nullptr), prev(nullptr) {}

template <class Type>
Stack<Type>::~Stack() {}

template <class Type>
void Stack<Type>::push(Type _data) {

    Stack<Type>* stack = new Stack<Type>();         // create new stack
    stack->data = _data;
    stack->next = nullptr;
    stack->prev = top;

    if (top != nullptr) {
        top->next = stack;
    }
    top = stack;
    length = length + 1;
}

template <class Type>
Type Stack<Type>::pop() {

    Type topData = top->data;
    
    if (top->prev != nullptr) {
        top = top->prev;
        delete top->next;
    } else {
        delete top;
        top = nullptr;
    }
    length = length - 1;

    return topData;
}

template <class Type>
void Stack<Type>::clear() {
    Stack<Type>* current = top;
    while(current->prev != nullptr) {
        current = current->prev;
        delete current->next;
    }
    delete current;
    top = nullptr;
    length = 0;
}

int main(int argc, char* argv[]) {

    Stack<float>* stack = new Stack<float>();
    stack->push(1.0F);
    stack->push(2.7F);
    stack->push(3.0F);
    stack->push(4.0F);
    stack->push(5.0F);

    std::cout << stack->pop() << std::endl;
    std::cout << stack->pop() << std::endl;
    std::cout << stack->pop() << std::endl;
    std::cout << stack->pop() << std::endl;
    std::cout << stack->pop() << std::endl;

    return 0;
}