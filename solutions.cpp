//
// Created by waterwoo on 2021/10/6.
//

#include "solutions.h"
#include <iostream>
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
        if (nums[j] < nums[j-1]){
            result = nums[j];
            ++i;
        }
    }
    return result;
}