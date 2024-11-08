#ifndef STACK_H
#define STACK_H

struct StackNode {
    int data;
    StackNode* next;
};

void push(StackNode*& top, int data);
int pop(StackNode*& top);

#endif