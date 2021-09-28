//
// Created by waterwoo on 2021/9/27.
//

#include "numDecodings.h"
#include <string>
#include <vector>

using namespace std;

int numDecodings::numDecodings1(string s) {
        int l = s.size();
        vector<int> dp(l+1);
        dp[0] = 1;
    for (int i = 1; i <= l; ++i) {
        if (s[i-1] != '0')
            dp[i] += dp[i-1];
        if (i > 1 && s[i-2] != '0' && (10 * (s[i-2] - '0') + s[i-1] - '0' <= 26))
            dp[i] += dp[i-2];
    }
    return dp[l];
}

int numDecodings::numDecodings2(string s) {
    int l = s.size();
    vector<long long> dp(l+1);
    dp[0] = 1;
    for (int i = 1; i <= l; ++i) {
        // 一个字符
        if (s[i-1] != '0' && s[i-1] != '*')
            dp[i] += dp[i-1];
        if (s[i-1] == '*')
            dp[i] += 9 * dp[i-1];

        // 两个字符
        if (i > 1 && s[i-2] != '0' && (10 * (s[i-2] - '0') + s[i-1] - '0' <= 26) && s[i-2] != '*' && s[i-1] != '*')
            dp[i] += dp[i-2];
        if (i > 1 && s[i-2] == '1' && s[i-1]<'7' && s[i-1] == '*'){
            dp[i] += 9*dp[i-2];
        }
        if (i > 1 && s[i-2] == '2' && s[i-1]<'7' && s[i-1] == '*'){
            dp[i] += 6*dp[i-2];
        }

        if (i > 1 && s[i-2] == '*' && s[i-1]>'6' && s[i-1] != '*'){
            dp[i] += dp[i-2];
        }
        if (i > 1 && s[i-2] == '*' && s[i-1] < '7' && s[i-1] != '*'){
            dp[i] += 2*dp[i-2];
        }
        if (i > 1 && s[i-2] == '*' && s[i-1] == '*'){
            dp[i] += 15*dp[i-2];
        }
        dp[i] = dp[i] % (1000000007);
    }
    return dp[l];
}

int numDecodings::numDecodings3(string s) {

        auto check1digit = [](char ch) -> int {
            if (ch == '0') {
                return 0;
            }
            return ch == '*' ? 9 : 1;
        };

        auto check2digits = [](char c0, char c1) -> int {
            if (c0 == '*' && c1 == '*') {
                return 15;
            }
            if (c0 == '*') {
                return c1 <= '6' ? 2 : 1;
            }
            if (c1 == '*') {
                if (c0 == '1') {
                    return 9;
                }
                if (c0 == '2') {
                    return 6;
                }
                return 0;
            }
            return c0 != '0' && (c0 - '0') * 10 + (c1 - '0') <= 26;
        };

        int n = s.size();
        // a = f[i-2], b = f[i-1], c = f[i]
        int a = 0, b = 1, c = 0;
        for (int i = 1; i <= n; ++i) {
            c = (long long)b * check1digit(s[i - 1]) % mod;
            if (i > 1) {
                c = (c + (long long)a * check2digits(s[i - 2], s[i - 1])) % mod;
            }
            a = b;
            b = c;
        }
        return c;

}