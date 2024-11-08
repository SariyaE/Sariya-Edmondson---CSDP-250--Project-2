// Sariya Edmondson
// CSDP 250
// Project 2
// 10/31/24

#include <iostream>
#include "Stack.h"
#include "Queue.h"

using namespace std;

void convertIntegerPart(int integerPart, int bitLimit) {
    StackNode* stackTop = nullptr;
    int bitCount = 0;
    
    while (integerPart > 0 && bitCount < bitLimit) {
        push(stackTop, integerPart % 2);
        integerPart /= 2;
        bitCount++;
    }
    
    while (bitCount < bitLimit) {
        push(stackTop, 0);
        bitCount++;
    }
    while (stackTop != nullptr) {
        cout << pop(stackTop);
    }
}

void convertDecimalPart(double decimalPart, int bitLimit) {
    QueueNode* queueFront = nullptr;
    QueueNode* queueRear = nullptr;
    int count = 0;

    while (decimalPart > 0 && count < bitLimit) {  
        decimalPart *= 2;
        int bit = static_cast<int>(decimalPart);
        enqueue(queueFront, queueRear, bit);
        decimalPart -= bit;
        count++;
    }
    printAndDequeue(queueFront);
}

int main() {
    double decimalNumber;
    int bitLimit;

    cout<<"Enter a decimal number: ";
    cin>>decimalNumber;

    cout<<"Enter the number of bits to display: ";
    cin>>bitLimit;

    int integerPart = static_cast <int> (decimalNumber);
    double decimalPart = decimalNumber - integerPart;

    cout<<"Binary Number: ";
    if (integerPart == 0) cout << "0";
    else convertIntegerPart(integerPart, bitLimit);

    if (decimalPart > 0) {
        cout<< ".";
        convertDecimalPart(decimalPart, bitLimit);
    }

    cout<<endl;
    return 0;
}
