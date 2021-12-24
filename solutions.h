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
#include <map>
#include <queue>
#include <math.h>
#include "binaryTreeNode.h"
#include <algorithm>
#include <cmath>


using namespace std;

class solutions {
public:
    int thirdMax(std::vector<int> &nums);

    int countSegments(std::string s);

    int integerBreak(int n);

    bool canPartition(std::vector<int> &nums);

    int lastStoneWeightII(std::vector<int> &stones);

    int maxSubArray(std::vector<int> &nums);

    int arrangeCoins(int n);

    static std::string three(int num);

    std::string numberToWords(int num);

    int divide(int dividend, int divisor);

    std::vector<std::string> fizzBuzz(int n);

    int findTargetSumWays(std::vector<int> &nums, int target);

    std::string countAndSay(int n);

    std::vector<std::string> readBinaryWatch(int turnedOn);

    int findComplement(int num);

    bool areNumbersAscending(std::string s);

    static bool cmp(const int &a, const int &b);

    std::vector<int> plusOne(std::vector<int> &digits);

    std::vector<int> majorityElement(std::vector<int> &nums);

    std::vector<int> majorityElementHash(std::vector<int> &nums);

    bool searchMatrix(vector<vector<int>> &matrix, int target);

    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2);

    bool isValid(string s);

    vector<string> removeInvalidParentheses(string s);

    bool reorderedPowerOf2(int n);

    bool isSelfCrossing(vector<int> &distance);

    static vector<string> findWords(vector<string> &words);

    int distributeCandies(vector<int> &candyType);

    int maxArea(vector<int> &height);

    int trap(vector<int> &height);

    int longestSubsequence(vector<int> &arr, int difference);

    int missingNumber(vector<int> &nums);

    int maxCount(int m, int n, vector<vector<int>> &ops);

    string getHint(string secret, string guess);

    int findPoisonedDuration(vector<int> &timeSeries, int duration);

    int getMoneyAmount(int n);

    bool detectCapitalUse(string word);

    bool isRectangleCover(vector<vector<int>> &rectangles);

    int maxProduct(vector<string> &words);

    int isCover(basic_string<char> &basicString, basic_string<char> &basicString1);

    int integerReplacement(int n);

    int findLHS(vector<int> &nums);

    void solveSudoku(vector<vector<char>> &board);

    vector<int> findAnagrams(string s, string p);

    int getN(int k);

    vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k);

    vector<int> serialize(TreeNode *root);

    TreeNode *deserialize(vector<int> data);

    bool buddyStrings(string s, string goal);

    int findLength(int n);

    int findNthDigit(int n);

    int findMinStep(string board, string hand);

    void adapt(string basicString);

    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k);

    string shortestCompletingWord(string licensePlate, vector<string> &words);

    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid);

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites);

    bool dfs(int i, int courses, vector<int> &visited, unordered_set<int> &visiting, vector<vector<int>> &prerequisites);

    int visiblePoints(vector<vector<int>> &points, int angle, vector<int> &location);

    int countBattleships(vector<vector<char>> &board);

    void bfs(int i, int j, vector<vector<char>> &vector, int &cnt);

    void vertical(int i, int j, vector<vector<char>> &vector);

    void horizontal(int i, int j, vector<vector<char>> &vector);

    bool repeatedSubstringPattern(string s);

    int repeatedStringMatch(string a, string b);

    int kmp(string haystack, string needle);
};

int count1(int n);


class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if (m == 0) {
            return 0;
        }
        vector<int> next(m);


        for (int i = 1, j = 0; i < m; i++) {
            while (j > 0 && needle[i] != needle[j]) {
                j = next[j - 1];
            }
            if (needle[i] == needle[j]) {
                j++;
            }
            next[i] = j;
        }


        for (int i = 0, j = 0; i < n; i++) {
            while (j > 0 && haystack[i] != needle[j]) {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j]) {
                j++;
            }
            if (j == m) {
                return i - m + 1;
            }
        }
        return -1;
    }
};


#endif //CPPPRACTICE_SOLUTIONS_H
