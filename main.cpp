#include <iostream>
#include <string>
#include "licenseKeyFormatting.h"
#include <time.h>
#include <vector>
#include "solutions.h"

using namespace std;


int main() {
    vector<int> nums{1,5,11,5};
    solutions sl;
    auto result = sl.canPartition(nums);
    cout << result << endl;
    return 0;
}
