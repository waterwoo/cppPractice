//
// Created by Waterwoo on 2021/10/21.
//

#ifndef CPPPRACTICE_MYFIRSTQUEUE_H
#define CPPPRACTICE_MYFIRSTQUEUE_H
#include <vector>

using namespace std;

class myFirstQueue {
private:
    // store elements
    vector<int> data;
    // a pointer to indicate the front position
    int p_start;


public:
    myFirstQueue() {p_start = 0;}
    /** Insert an element into the queue. Return true if the operation is successful. */
    bool enQueue(int x);
    /** Delete an element from the queue. Return true if the operation is successful. */
    bool deQueue();
    /** Get the front item from the queue. */
    int Front();
    /** Checks whether the queue is empty or not. */
    bool isEmpty();
};


#endif //CPPPRACTICE_MYFIRSTQUEUE_H
