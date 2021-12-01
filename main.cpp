#include <iostream>
#include "solutions.h"

using namespace std;


int main() {
    solutions sl;
    vector<int> arr{1,7,23,29,47};
    int k= pow(2,31)-1;
    auto ans = sl.findNthDigit(k);

    cout << ans << endl;

    return 0;
}
