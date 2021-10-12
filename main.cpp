#include <iostream>
#include <string>
#include "licenseKeyFormatting.h"
#include <time.h>
#include <vector>
#include "solutions.h"
#include <math.h>

using namespace std;


int main() {
    vector<int> nums{31,26,33,21,40};
solutions sl;
//int num=123;
    auto result = sl.lastStoneWeightII(nums);
    cout<< result << endl;
    return 0;
}
