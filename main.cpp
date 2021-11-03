#include <iostream>
#include <string>
#include "licenseKeyFormatting.h"
//#include <time.h>
#include <vector>
#include "solutions.h"
//#include <math.h>
#include "myFirstQueue.h"
#include "MyCircularQueue.h"


using namespace std;


int main() {
    solutions sl;

    vector<int> nums{0,1,0,2,1,0,1,3,2,1,2,1};

    auto result = sl.trap(nums);
//    for (auto w:result) {
//        cout<< w <<"**";
//    }
    cout<< result <<endl;

    return 0;
}
