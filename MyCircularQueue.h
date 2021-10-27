//
// Created by Waterwoo on 2021/10/21.
//

#ifndef CPPPRACTICE_MYCIRCULARQUEUE_H
#define CPPPRACTICE_MYCIRCULARQUEUE_H
#include <iostream>
#include <vector>

#define error -1

using namespace std;


class MyCircularQueue {
private:
    vector<int> Data;
    int front;
    int rear;
    int maxSize;
public:
    MyCircularQueue(int maxSize) {
        this->maxSize=maxSize+1;
        Data = vector<int>(maxSize+1,0);
        front = 0;
        rear = front;
    }

    /** Insert an element into the queue. Return true if the operation is successful. */
    bool enQueue(int x);

    /** Delete an element from the queue. Return true if the operation is successful. */
    bool deQueue();

    /** Get the front item from the queue. */
    int Front();

    int Rear();

    /** Checks whether the queue is empty or not. */
    bool isEmpty() const;

    /** Checks whether the queue is full or not. */
    bool isFull() const;
};


#endif //CPPPRACTICE_MYCIRCULARQUEUE_H
