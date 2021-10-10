#include <iostream>
#include <string>
#include "licenseKeyFormatting.h"
#include <time.h>
#include <vector>
#include "solutions.h"

using namespace std;


int main() {
    vector<int> nums{-2};
    solutions sl;
    auto result = sl.maxSubArray(nums);
    cout<< result << endl;
    return 0;
}
