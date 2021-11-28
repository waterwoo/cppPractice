#include <iostream>
#include "solutions.h"

using namespace std;


int main() {
    solutions sl;
    string s{"cbaebabacd"}, p{"abc"};
    auto ans = sl.findAnagrams(s, p);
    for (auto c: ans) {
        cout << c << endl;
    }
    return 0;
}
