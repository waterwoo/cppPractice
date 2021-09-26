//
// Created by waterwoo on 2021/9/26.
//

#ifndef CPPPRACTICE_SUMOFTWOINT_H
#define CPPPRACTICE_SUMOFTWOINT_H


class sumOfTwoInt {
public:
    int getSum(int a, int b) {
        // 自己写的，复杂了
        //        unsigned c=a^b, d=a&b;
        //        while (a&b){
        //            c = a^b;
        //            d = a&b;
        //            a = c;
        //            b = (d<<1);
        //        }
        //        return a^b;


        // 官方题解
        while (b != 0) {
            unsigned int carry = (unsigned int)(a & b) << 1;
            a = a ^ b;
            b = carry;
        }
        return a;
    }
};


#endif //CPPPRACTICE_SUMOFTWOINT_H
