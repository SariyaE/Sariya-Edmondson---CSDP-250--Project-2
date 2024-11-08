#include "Stack.h"
#include <iostream>

void push(StackNode*& top, int data) {
    StackNode* newNode = new StackNode;
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

int pop(StackNode*& top) {
    if (top == nullptr) return -1; 
    int data = top->data;
    StackNode* temp = top;
    top = top->next;
    delete temp;
    return data;
}
