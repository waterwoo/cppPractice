#include <iostream>
#include <string>
#include "licenseKeyFormatting.h"
#include <time.h>
#include <vector>
#include "solutions.h"
#include <math.h>

using namespace std;


int main() {
    solutions sl;
    std::string s="this 1 4 fjld 42 89 89 jsf";
    auto result = sl.areNumbersAscending(s);
    cout << result << endl;
    return 0;
}
