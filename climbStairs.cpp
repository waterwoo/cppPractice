//
// Created by waterwoo on 2021/9/26.
//

#include "climbStairs.h"
#include <vector>


using namespace std;

int climbstairs::climbStairs(int n) {
    vector<int> f(n+1);
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i <= n; ++i) {
        f[i] = f[i-1] + f[i-2];
    }
    return f[n];
}
