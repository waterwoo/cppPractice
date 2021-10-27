//
// Created by waterwoo on 2021/10/6.
//

#include "solutions.h"
#include <algorithm>
#include<numeric>

using namespace std;

int solutions::thirdMax(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    std::reverse(nums.begin(), nums.end());
    auto length = nums.size();
    int i = 0;
    int result = nums[0];
    for (int j = 1; j < length; ++j) {
        if (i == 2)
            break;
        if (nums[j] < nums[j - 1]) {
            result = nums[j];
            ++i;
        }
    }
    if (i < 2)
        return nums[0];
    else
        return result;
}

int solutions::countSegments(std::string s) {
    int length = s.size();
    int count = 0;
    for (int i = 0; i < length; ++i) {
        if (s[i] != ' ') {
            ++count;
            while (s[i] != ' ' && i < length)
                ++i;
        }
    }
    return count;
}

int solutions::integerBreak(int n) {
    std::vector<int> dp(n + 1);
    dp[2] = 1;
    int maxS = 0;
    for (int i = 3; i <= n; ++i) {
        for (int j = 1; j <= i / 2; ++j) {
            maxS = std::max(std::max(j * (i - j), j * dp[i - j]), maxS);
        }
        dp[i] = maxS;
    }
    return dp[n];
}

bool solutions::canPartition(std::vector<int> &nums) {
    auto n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int maxNum = *max_element(nums.begin(), nums.end());
    if (sum % 2)
        return false;
    int target = sum / 2;
    if (maxNum > target)
        return false;
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    for (int i = 0; i < n; ++i) {
        dp[i][0] = 1;
    }
    dp[0][nums[0]] = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= target; ++j) {
            if (j - nums[i] > 0)
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n - 1][target];
}

int solutions::lastStoneWeightII(vector<int> &stones) {
    int sum = accumulate(stones.begin(), stones.end(), 0);
    auto n = stones.size();
    // 偶数和1位与运算,结果为0
//    if (sum & 1)
//        return 0;
    int target = sum / 2;
    cout << "SUM: " << sum << "*** target: " << target << "**N: " << n << endl;


    vector<vector<int>> dp(n, vector<int>(target + 1));

    for (int i = stones[0]; i < target + 1; ++i) {
        dp[0][i] = stones[0];
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < target + 1; ++j) {
            if (stones[i] <= j)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stones[i]] + stones[i]);
            else dp[i][j] = dp[i - 1][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < target + 1; ++j) {
            cout << dp[i][j] << "\t";
        }
        cout << endl;
    }

    return sum - 2 * dp[n - 1][target];
}

int solutions::maxSubArray(vector<int> &nums) {
    int thisSubSum = 0, maxSum = 0;
    int maxEle = *max_element(nums.begin(), nums.end());
    unsigned n = nums.size();
    for (int i = 0; i < n; ++i) {
        thisSubSum += nums[i];
        if (thisSubSum < 0)
            thisSubSum = 0;
        if (thisSubSum > maxSum)
            maxSum = thisSubSum;
    }
    if (maxSum)
        return maxSum;
    else
        return maxEle;
}

int solutions::arrangeCoins(int n) {
    int sum = 0, i;
    for (i = 1; i < n; ++i) {
        sum += i;
        if (sum == n)
            return i;
        if (sum > n)
            return i - 1;
    }
    return 0;
}


string solutions::three(int num) {
    string result;
    // 三位数
    vector<string> gSome{"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten"};
    vector<string> tenSome{"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
                           "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens{"", "", "Twenty", "Thirty", "Forty", "Fifty",
                        "Sixty", "Seventy", "Eighty", "Ninety"};

    int h = num / 100;        // 百
    int tg = num % 100;
    int t = num % 100 / 10;     // 十
    int g = num % 100 % 10;     // 个
    if (h)
        result += (gSome[h] + " Hundred ");
    if (tg < 20 && tg > 9) {
        result += (tenSome[tg - 10]);
        return result;
    } else {
        if (t)
            result += (tens[t] + " ");
        if (g)
            result += (gSome[g]);
    }
    auto l = result.size();
    if (result.back() == ' ')
        result.erase(l - 1, 1);
    return result;
}

string solutions::numberToWords(int num) {

    if (num == 0)
        return "Zero";

    vector<string> name{"Thousand", "Million", "Billion"};
    string result = three(num % 1000);
    num /= 1000;
    int i = 0;
    while (num / 1000) {
        if (!three(num % 1000).empty())
            result = (three(num % 1000) + " " + name[i] + " ").append(result);
        ++i;
        num /= 1000;
    }
    if (!three(num % 1000).empty())
        result = (three(num % 1000) + " " + name[i++] + " ").append(result);
    auto l = result.size();
    if (result.back() == ' ')
        return result.substr(0, l - 1);
    return result;
}

int solutions::divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;
    if (divisor == 1)
        return dividend;

    bool flag = true;
    if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))
        flag = false;
    if (dividend > 0) dividend = -dividend;
    if (divisor > 0) divisor = -divisor;

    int ans = 0;
    while (1) {
        int a = dividend, b = divisor, cnt = 1;
        if (a > b) break;
        while (a - b <= b) {
            cnt += cnt;
            b += b;
        }
        ans += cnt;
        dividend -= b;
    }
    return flag ? ans : -ans;

}

vector<string> solutions::fizzBuzz(int n) {
//    vector<string> result;
//    for (int i = 1; i <= n; ++i) {
//        if (i%3 && i%5)
//            result.emplace_back(to_string(i));
//        else if(i%15==0)
//            result.emplace_back("FizzBuzz");
//        else if (i%3==0)
//            result.emplace_back("Fizz");
//        else
//            result.emplace_back("Buzz");
//    }
//    return result;
    vector<string> result;
    for (int i = 1; i <= n; ++i) {
        if (i % 3 && i % 5)
            result.emplace_back(to_string(i));
        else if (i % 15 == 0)
            result.emplace_back("FizzBuzz");
        else if (i % 3 == 0)
            result.emplace_back("Fizz");
        else
            result.emplace_back("Buzz");
    }
    return result;
}

int solutions::findTargetSumWays(vector<int> &nums, int target) {
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if ((sum - target) & 1)
        return 0;
    int left = (sum - target) / 2;

    cout << left << endl;

    vector<vector<int>> dp(n + 1, vector<int>(left + 1));

    dp[0][0] = 1;
//    for (int i = 0; i < n; ++i) {
//        dp[i][0] = 1;
//    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= left; ++j) {
            dp[i][j] += dp[i - 1][j];
            if (j >= nums[i - 1])
                dp[i][j] += dp[i - 1][j - nums[i - 1]];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= left; ++j) {
            cout << dp[i][j] << "\t";
        }
        cout << endl;
    }
    return dp[n][left];
}

std::string solutions::countAndSay(int n) {
    if (n == 1)
        return "1";
    string s = "1";
    int nx;
    string thisResult;
    // 进行n次迭代
    for (int i = 0; i < n - 1; ++i) {
        nx = 0;
        char tmp = s[0];
        thisResult = "";
        // 对每一个字符串:
        for (int j = 0; j < s.size(); j++) {
            if (tmp != s[j]) {
                thisResult.append(to_string(nx) + s[j - 1]);
                tmp = s[j];
                nx = 0;
            }
            nx++;
        }
        thisResult.append(to_string(nx) + tmp);
        s = thisResult;
    }
    return thisResult;
}

std::vector<std::string> solutions::readBinaryWatch(int turnedOn) {
    vector<string> result;
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 60; ++j) {
            if ((count1(i) + count1(j)) == turnedOn)
                result.push_back(to_string(i) + ":" + (j < 10 ? "0" + to_string(j) : to_string(j)));
        }
    }

    return result;

}

int count1(int n) {
    int res = 0;
    while (n != 0) {
        n = n & (n - 1);
        res++;
    }
    return res;
}

int solutions::findComplement(int num) {
    // 找到最高位的1，左移一位并-1，异或
    int highBit = 1;
    int x = num;
    while (x != 0) {
        // 找最低位（最右边）的 1
        highBit = x & (-x);
        // 打掉最低位（最右边）的1
        x = x & (x - 1);
    }
    long xm = ((highBit << 1) - 1);
    return num ^ xm;
}

bool solutions::areNumbersAscending(std::string s) {
    vector<int> nums;
    for (int i = 0; i < s.size(); ++i) {
        if (isdigit(s[i])) {
            int n = (s[i] - '0');
            int j = i + 1;
            for (j; j < s.size(); ++j) {
                if (isdigit(s[j]))
                    n = (n * 10 + (s[j] - '0'));
                else break;
            }
            nums.push_back(n);
            i = j;
        }
    }
    if (std::is_sorted(nums.begin(), nums.end(), cmp))
        return true;
    else
        return false;
}

bool solutions::cmp(const int &a, const int &b) {
    return a <= b;
}

std::vector<int> solutions::plusOne(vector<int> &digits) {
    if (digits[0]==0)
        return vector<int>{1};
    if (digits.size()==1 && digits[0]==9){
        return vector<int> {1,0};
    }
    if (digits.back()!=9){
        digits.back()++;
        return digits;
    } else {
        digits.back()=0;
        vector<int> ar(digits.begin(), digits.end()-1);
        auto re = plusOne(ar);
        re.push_back(0);
        return re;
    }
}

std::vector<int> solutions::majorityElement(vector<int> &nums) {
    vector<int> result;
    int n = nums.size();
    std::sort(nums.begin(), nums.end());
    int count=1;
    for (int i = 1; i < n; ++i) {
        if (nums[i]==nums[i-1]){
            count++;
        } else {
            if (count>(n/3))
                result.emplace_back(nums[i-1]);
            count=1;
        }
    }
    if (count>(n/3))
        result.emplace_back(nums.back());
    return result;
}

std::vector<int> solutions::majorityElementHash(vector<int> &nums) {
    int n = nums.size();
    vector<int> ans;
    unordered_map<int, int> cnt;

    for (auto & v : nums) {
        cnt[v]++;
    }
    for (auto & v : cnt) {
        if (v.second > n / 3) {
            ans.push_back(v.first);
        }
    }
    return ans;
}

bool solutions::searchMatrix(vector<vector<int>> &matrix, int target) {
    // 先左右后上下
    int m=matrix.size(),n=matrix[0].size();
    int mid;
    for (int i = 0; i < m; ++i) {
        int left=0, right=n-1;
        while(left<=right){
            mid=(right+left)/2;
            if (matrix[i][mid]<target){
                left=mid+1;
            } else
            if (matrix[i][mid]>target){
                right=mid-1;
            } else{
                return true;
            }
        }
    }

    return false;
}

vector<int> solutions::nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    int mm=nums1.size();
    vector<int> ans(mm,-1);
    for (int i=0;i<mm;i++) {
        auto m=find(nums2.begin(), nums2.end(), nums1[i]);
        for (; m != nums2.end(); m++) {
            if (*m>nums1[i]){
                ans[i]=*m;
                break;
            }
        }
    }
    return ans;
//    int m = nums1.size();
//    int n = nums2.size();
//    vector<int> res(m);
//    for (int i = 0; i < m; ++i) {
//        int j = 0;
//        while (j < n && nums2[j] != nums1[i]) {
//            ++j;
//        }
//        int k = j + 1;
//        while (k < n && nums2[k] < nums2[j]) {
//            ++k;
//        }
//        res[i] = k < n ? nums2[k] : -1;
//    }
//    return res;

}

bool solutions::isValid(string s) {
    stack<int> stk;
    for (auto ch: s) {
        if (!stk.empty()){
            switch (ch) {
                case '(':
                case '{':
                case '[':
                    stk.push(ch);
                    break;
                case ')':
                    if (stk.top()=='(')
                        stk.pop();
                    else stk.push(ch);
                    break;
                case ']':
                    if (stk.top()=='[')
                        stk.pop();
                    else stk.push(ch);
                    break;
                case '}':
                    if (stk.top()=='{')
                        stk.pop();
                    else stk.push(ch);
                    break;
                default:
                    break;
            }
        } else
            stk.push(ch);
    }
    if (stk.empty())
        return true;
    else
        return false;
}

struct node{
    int pos;
    char val;
};
vector<string> solutions::removeInvalidParentheses(string s) {
    auto ss=s;
    stack<node> stk;
    for (int i=0;i<s.size();++i) {
        if (!stk.empty()){
            switch (s[i]) {
                case '(':
                    stk.push({i, s[i]});
                    break;
                case ')':
                    if (stk.top().val=='(')
                        stk.pop();
                    else
                        stk.push({i, s[i]});
                    break;
                default:
                    break;
            }
        } else
            stk.push({i, s[i]});
    }
    while (!stk.empty()){
        ss.erase(stk.top().pos);
        stk.pop();
    }
    vector<string> result;
    result.emplace_back(ss);
    return result;
}
