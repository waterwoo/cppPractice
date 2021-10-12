#include <iostream>
#include <string>
#include "licenseKeyFormatting.h"
#include <time.h>
#include <vector>
#include "solutions.h"
#include <math.h>

using namespace std;


int main() {
//    vector<int> nums{14,1,7,17,8,10};
    solutions sl;
int t=-122,n=300;

    auto result = sl.divide(t,n);
    cout<< result << "  "<<pow(2,10)<< endl;
    return 0;
}
