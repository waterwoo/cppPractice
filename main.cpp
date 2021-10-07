#include <iostream>
#include <string>
#include "licenseKeyFormatting.h"
#include <time.h>
#include <vector>
#include "solutions.h"

using namespace std;


int main() {
    vector<int> nums{1,2,3,4,5,8,9};
    solutions sl;
    auto result = sl.thirdMax(nums);
    cout << result << endl;
    return 0;
}
