//
// Created by Waterwoo on 2021/10/21.
//

#include "MyCircularQueue.h"

bool MyCircularQueue::enQueue(int x) {
    if (isFull())
        return false;
    rear = ((rear + 1) % maxSize);
    Data[rear] = x;
    return true;
}

bool MyCircularQueue::deQueue() {
    if (isEmpty())
        return false;
    front = ((front + 1) % maxSize);
    Data[front] = 0;
    return true;
}

int MyCircularQueue::Front() {
    if (isEmpty())
        return -1;
    return Data[(front + 1) % maxSize];
}

int MyCircularQueue::Rear() {
    if (isEmpty())
        return -1;
    return Data[rear];
}

bool MyCircularQueue::isEmpty() const {
    return (front == rear);
}

bool MyCircularQueue::isFull() const {
    return (((rear + 1) % maxSize) == front);
}
