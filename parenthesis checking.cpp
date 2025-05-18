#include <iostream>
#include <cstdlib>
using namespace std;

struct stack {
    int size;
    char* arr;
    int top;
};

void push(struct stack* ptr, char data) {
    if (ptr->top == ptr->size - 1) {
        cout << "Stack overflow! Cannot add " << data << " to the stack" << endl;
    } else {
        ptr->top++;
        ptr->arr[ptr->top] = data;
        cout << "Added successfully: " << data << endl;
    }
}

char pop(struct stack* ptr) {
    if (ptr->top == -1) {
        cout << "Stack underflow! Cannot delete from empty stack" << endl;
        return -1; // Indicating underflow
    } else {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        cout << "Deleted: " << val << endl;
        return val; // Return the popped value
    }
}

int parenthesisMatch(const char* exp) {
    // Dynamically allocate the stack
    struct stack* sp = (struct stack*)malloc(sizeof(struct stack));
    sp->size = 15; // Define stack size
    sp->top = -1;
    sp->arr = (char*)malloc(sp->size * sizeof(char));
    char pop_ch;

    // Check the expression
    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '['  || exp[i] == '{') {
            push(sp, '('); // Push opening parenthesis
        } else if (exp[i] == ')' || exp[i] == ']'  || exp[i] == '}') {
            if (sp->top == -1) { // Stack underflow
                free(sp->arr);
                free(sp);
                return 0; // Parentheses mismatch
            }
            pop(sp); // Pop the matching parenthesis
        }
    }

    // If the stack is empty, parentheses are balanced
    int result = (sp->top == -1);
    free(sp->arr); // Free memory
    free(sp);
    return result;
}

int main() {
    const char* exp = "7*25)";

    if (parenthesisMatch(exp)) {
        cout << "The parentheses are matching." << endl;
    } else {
        cout << "The parentheses do not match." << endl;
    }

    return 0;
}
