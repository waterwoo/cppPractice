//
// Created by waterwoo on 2021/10/6.
//

#include "solutions.h"
#include <algorithm>

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
    std::vector<int> dp(n+1);
    dp[2] = 1;
    for (int i = 3; i <= n; ++i) {

    }
    return dp[n];
}
