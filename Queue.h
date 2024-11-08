#ifndef QUEUE_H
#define QUEUE_H

struct QueueNode {
    int data;
    QueueNode* next;
};

void enqueue(QueueNode*& front, QueueNode*& rear, int data);
void printAndDequeue(QueueNode*& front);

#endif