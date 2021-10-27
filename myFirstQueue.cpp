//
// Created by Waterwoo on 2021/10/21.
//

#include "myFirstQueue.h"

bool myFirstQueue::enQueue(int x) {
    data.push_back(x);
    return true;
}

bool myFirstQueue::deQueue() {
    if (isEmpty()) {
        return false;
    }
    p_start++;
    return true;
}

int myFirstQueue::Front() {
    return data[p_start];
}

bool myFirstQueue::isEmpty() {
    return p_start >= data.size();
}
