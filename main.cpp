#include <iostream>
#include <string>
#include "licenseKeyFormatting.h"
#include <time.h>
#include <vector>
#include "solutions.h"

using namespace std;


int main() {
    string s = "a b c d";
    solutions sl;
    auto result = sl.countSegments(s);
    cout << result << endl;
    return 0;
}
