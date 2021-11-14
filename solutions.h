//
// Created by waterwoo on 2021/10/6.
//

#ifndef CPPPRACTICE_SOLUTIONS_H
#define CPPPRACTICE_SOLUTIONS_H
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;
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
    std::vector<int> plusOne(std::vector<int>& digits);
    std::vector<int> majorityElement(std::vector<int>& nums);
    std::vector<int> majorityElementHash(std::vector<int>& nums);
    bool searchMatrix(vector<vector<int>>& matrix, int target);
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2);
    bool isValid(string s);
    vector<string> removeInvalidParentheses(string s);
    bool reorderedPowerOf2(int n);
    bool isSelfCrossing(vector<int>& distance);
    static vector<string> findWords(vector<string>& words);
    int distributeCandies(vector<int>& candyType);
    int maxArea(vector<int>& height);
    int trap(vector<int>& height);
    int longestSubsequence(vector<int>& arr, int difference);
    int missingNumber(vector<int>& nums);
    int maxCount(int m, int n, vector<vector<int>>& ops);
    string getHint(string secret, string guess);
    int findPoisonedDuration(vector<int>& timeSeries, int duration);
    int getMoneyAmount(int n) ;
    bool detectCapitalUse(string word);

    };

int count1(int n);


#endif //CPPPRACTICE_SOLUTIONS_H
