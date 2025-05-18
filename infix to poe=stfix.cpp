#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

struct stack {
    int size;
    char* arr;
    int top;
};

int stackTop(struct stack* ptr) {
    return ptr->arr[ptr->top];
}

int precedence(char ch) {
    if (ch == '*' || ch == '/') {
        return 3;
    } else if (ch == '+' || ch == '-') {
        return 2;
    } else {
        return 0;
    }
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

void push(struct stack* ptr, char data) {
    if (ptr->top == ptr->size - 1) {
        cout << "Stack overflow! Cannot add " << data << " to the stack" << endl;
    } else {
        ptr->top++;
        ptr->arr[ptr->top] = data;
    }
}

char pop(struct stack* ptr) {
    if (ptr->top == -1) {
        cout << "Stack underflow! Cannot delete from empty stack" << endl;
        return -1; // Indicating underflow
    } else {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

char* infixToPostfix(const char* infix) {
    struct stack* sp = (struct stack*)malloc(sizeof(struct stack));
    sp->size = strlen(infix);
    sp->arr = (char*)malloc(sp->size * sizeof(char));
    sp->top = -1;

    char* postfix = (char*)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        if (!isOperator(infix[i]) && infix[i] != '(' && infix[i] != ')') {
            postfix[j] = infix[i];
            i++;
            j++;
        } else if (infix[i] == '(') {
            push(sp, infix[i]);
            i++;
        } else if (infix[i] == ')') {
            while (sp->top != -1 && stackTop(sp) != '(') {
                postfix[j] = pop(sp);
                j++;
            }
            if (sp->top != -1 && stackTop(sp) == '(') {
                pop(sp); // Remove '(' from stack
            }
            i++;
        } else {
            while (sp->top != -1 && precedence(stackTop(sp)) >= precedence(infix[i])) {
                postfix[j] = pop(sp);
                j++;
            }
            push(sp, infix[i]);
            i++;
        }
    }

    while (sp->top != -1) {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';

    free(sp->arr);
    free(sp);
    return postfix;
}

int main() {
    const char* infix = "a*b+d-y/x";

    cout << "Postfix expression of " << infix << " is " << infixToPostfix(infix) << endl;

    return 0;
}
