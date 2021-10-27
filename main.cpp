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
    string s="()()((";

    auto result = sl.removeInvalidParentheses(s);
        cout<< result[0] <<endl;

    return 0;
}
