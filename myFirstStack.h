//
// Created by Waterwoo on 2021/10/13.
//

#ifndef CPPPRACTICE_MYFIRSTSTACK_H
#define CPPPRACTICE_MYFIRSTSTACK_H

#include <vector>
#define MaxSize 10


using ElementType = int;

//class Snode *Stack;
class Snode{
public:
    std::vector<int> Data[10];
    int Top;

//    void Push(Stack Ptrs, ElementType item);
    void Pop();


};



#endif //CPPPRACTICE_MYFIRSTSTACK_H
