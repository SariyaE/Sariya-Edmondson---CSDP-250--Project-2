#include "Queue.h"
#include <iostream>
using namespace std;

void enqueue(QueueNode*& front, QueueNode*& rear, int data) {
    QueueNode* newNode = new QueueNode;
    newNode->data = data;
    newNode->next = nullptr;
    if (rear != nullptr) rear->next = newNode;
    rear = newNode;
    if (front == nullptr) front = rear;
}

void printAndDequeue(QueueNode*& front) {
    while (front != nullptr) {
        cout << front->data;
        QueueNode* temp = front;
        front = front->next;
        delete temp;
    }
}