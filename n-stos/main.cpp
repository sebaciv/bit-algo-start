#include <iostream>

using namespace std;

struct node {
    int value;
    node* next;
};

bool isEmpty(node *&first) {
    return first->next == NULL;
}

int top(node *&first) {
    if (isEmpty(first)) {
        throw "top of empty empty";
    } else {
        return first->value;
    }
}

void pop(node *&first) {
    if (isEmpty(first)) {
        return;
    } else {
        node *tmp;
        tmp=first;
        first=first->next;
        delete tmp;
    }
}

void push(node *&first, int n) {
    node *p = new node;
    p->value = n;
    p->next = first;
    first = p;
}

int main() {
    int z;
    cin >> z;
    node *stack = new node;
    stack->next = NULL;
    for (int i = 0; i < z; i++) {
        string operation;
        cin >> operation;
        if (operation == "TOP") {
            if (isEmpty(stack)) {
                cout << "EMPTY" << endl;
            } else {
                cout << top(stack) << endl;
            }
        } else if (operation == "POP") {
            pop(stack);
        } else {
            int n;
            cin >> n;
            push(stack, n);
        }
    }
    return 0;
}
