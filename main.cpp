#include <iostream>
#include "solutions.h"

using namespace std;


int main() {
    solutions sl;
    string a = "mississippi", b = "issip";
    cout << sl.kmp(a,b);
    return 0;
}
