//
// Created by waterwoo on 2021/10/6.
//

#include "solutions.h"
#include <algorithm>
#include<numeric>

using namespace std;

int solutions::thirdMax(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    std::reverse(nums.begin(), nums.end());
    auto length = nums.size();
    int i = 0;
    int result = nums[0];
    for (int j = 1; j < length; ++j) {
        if (i == 2)
            break;
        if (nums[j] < nums[j - 1]) {
            result = nums[j];
            ++i;
        }
    }
    if (i < 2)
        return nums[0];
    else
        return result;
}

int solutions::countSegments(std::string s) {
    int length = s.size();
    int count = 0;
    for (int i = 0; i < length; ++i) {
        if (s[i] != ' ') {
            ++count;
            while (s[i] != ' ' && i < length)
                ++i;
        }
    }
    return count;
}

int solutions::integerBreak(int n) {
    std::vector<int> dp(n + 1);
    dp[2] = 1;
    int maxS = 0;
    for (int i = 3; i <= n; ++i) {
        for (int j = 1; j <= i / 2; ++j) {
            maxS = std::max(std::max(j * (i - j), j * dp[i - j]), maxS);
        }
        dp[i] = maxS;
    }
    return dp[n];
}

bool solutions::canPartition(std::vector<int> &nums) {
    auto n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int maxNum = *max_element(nums.begin(), nums.end());
    if (sum % 2)
        return false;
    int target = sum / 2;
    if (maxNum > target)
        return false;
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    for (int i = 0; i < n; ++i) {
        dp[i][0] = 1;
    }
    dp[0][nums[0]] = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= target; ++j) {
            if (j - nums[i] > 0)
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n - 1][target];
}

int solutions::lastStoneWeightII(vector<int> &stones) {
    int sum = accumulate(stones.begin(), stones.end(), 0);
    // 偶数和1位与运算,结果为0
    if (sum & 1)
        return false;

    return 0;
}

int solutions::maxSubArray(vector<int> &nums) {
    int thisSubSum = 0, maxSum = 0;
    int maxEle = *max_element(nums.begin(), nums.end());
    unsigned n = nums.size();
    for (int i = 0; i < n; ++i) {
        thisSubSum += nums[i];
        if (thisSubSum < 0)
            thisSubSum = 0;
        if (thisSubSum > maxSum)
            maxSum = thisSubSum;
    }
    if (maxSum)
        return maxSum;
    else
        return maxEle;
}

int solutions::arrangeCoins(int n) {
    int sum = 0, i;
    for (i = 1; i < n; ++i) {
        sum += i;
        if (sum == n)
            return i;
        if (sum > n)
            return i - 1;
    }
    return 0;
}

string solutions::three(int num) {
    string result;
    // 三位数
    vector<string> gSome{"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten"};
    vector<string> tenSome{"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
                           "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens{"", "Twenty", "Thirty", "Forty", "Fifty",
                        "Sixty", "Seventy", "Eighty", "Ninety"};
    int h = num / 100;        // 百
    int tg = num % 100;
    int t = num % 100 / 10;     // 十
    int g = num % 100 % 10;     // 个
    if (h)
        result += (gSome[h] + " Hundred ");
    if (tg < 20 && tg > 9) {
        result += (tenSome[tg - 10]);
        return result;
    } else {
        if (t)
            result += (tens[t] + " " + gSome[g]);
    }
    return result;
}

string solutions::numberToWords(int num) {
//    "Two Billion One Hundred Forty Seven Million Four Hundred Eighty Three Thousand Six Hundred Forty Seven"
    vector<string> name{"Thousand", "Million", "Billion"};
    vector<string> ten{"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
                       "Seventeen", "Eighteen", "Nineteen", "Twenty", "Thirty", "Forty", "Fifty",
                       "Sixty", "Seventy", "Eighty", "Ninety"};
    return name[0];
}

