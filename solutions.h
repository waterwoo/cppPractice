//
// Created by waterwoo on 2021/10/6.
//

#ifndef CPPPRACTICE_SOLUTIONS_H
#define CPPPRACTICE_SOLUTIONS_H
#include <vector>
#include <string>
#include <iostream>

class solutions {
public:
    int thirdMax(std::vector<int>& nums);
    int countSegments(std::string s);
    int integerBreak(int n);
    bool canPartition(std::vector<int>& nums);
    int lastStoneWeightII(std::vector<int>& stones);
    int maxSubArray(std::vector<int>& nums);
    int arrangeCoins(int n);
    static std::string three(int num);
    std::string numberToWords(int num);
    int divide(int dividend, int divisor);
    std::vector<std::string> fizzBuzz(int n);
    int findTargetSumWays(std::vector<int>& nums, int target);
    std::string countAndSay(int n);
    std::vector<std::string> readBinaryWatch(int turnedOn);
    int findComplement(int num);
    bool areNumbersAscending(std::string s);

    static bool cmp(const int &a, const int &b);
};

int count1(int n);


#endif //CPPPRACTICE_SOLUTIONS_H
