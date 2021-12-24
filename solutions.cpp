//
// Created by waterwoo on 2021/10/6.
//

#include "solutions.h"
#include <algorithm>
#include<numeric>
#include <climits>

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
    if (dividend == INT32_MIN && divisor == -1)
        return INT32_MIN;
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
    if (digits[0] == 0)
        return vector<int>{1};
    if (digits.size() == 1 && digits[0] == 9) {
        return vector<int>{1, 0};
    }
    if (digits.back() != 9) {
        digits.back()++;
        return digits;
    } else {
        digits.back() = 0;
        vector<int> ar(digits.begin(), digits.end() - 1);
        auto re = plusOne(ar);
        re.push_back(0);
        return re;
    }
}

std::vector<int> solutions::majorityElement(vector<int> &nums) {
    vector<int> result;
    int n = nums.size();
    std::sort(nums.begin(), nums.end());
    int count = 1;
    for (int i = 1; i < n; ++i) {
        if (nums[i] == nums[i - 1]) {
            count++;
        } else {
            if (count > (n / 3))
                result.emplace_back(nums[i - 1]);
            count = 1;
        }
    }
    if (count > (n / 3))
        result.emplace_back(nums.back());
    return result;
}

std::vector<int> solutions::majorityElementHash(vector<int> &nums) {
    int n = nums.size();
    vector<int> ans;
    unordered_map<int, int> cnt;

    for (auto &v: nums) {
        cnt[v]++;
    }
    for (auto &v: cnt) {
        if (v.second > n / 3) {
            ans.push_back(v.first);
        }
    }
    return ans;
}

bool solutions::searchMatrix(vector<vector<int>> &matrix, int target) {
    // 先左右后上下
    int m = matrix.size(), n = matrix[0].size();
    int mid;
    for (int i = 0; i < m; ++i) {
        int left = 0, right = n - 1;
        while (left <= right) {
            mid = (right + left) / 2;
            if (matrix[i][mid] < target) {
                left = mid + 1;
            } else if (matrix[i][mid] > target) {
                right = mid - 1;
            } else {
                return true;
            }
        }
    }

    return false;
}

vector<int> solutions::nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    int mm = nums1.size();
    vector<int> ans(mm, -1);
    for (int i = 0; i < mm; i++) {
        auto m = find(nums2.begin(), nums2.end(), nums1[i]);
        for (; m != nums2.end(); m++) {
            if (*m > nums1[i]) {
                ans[i] = *m;
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
        if (!stk.empty()) {
            switch (ch) {
                case '(':
                case '{':
                case '[':
                    stk.push(ch);
                    break;
                case ')':
                    if (stk.top() == '(')
                        stk.pop();
                    else stk.push(ch);
                    break;
                case ']':
                    if (stk.top() == '[')
                        stk.pop();
                    else stk.push(ch);
                    break;
                case '}':
                    if (stk.top() == '{')
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

struct node {
    int pos;
    char val;
};

vector<string> solutions::removeInvalidParentheses(string s) {
    auto ss = s, sss = s;
    stack<node> stk;
    for (int i = 0; i < s.size(); ++i) {
        if (!stk.empty()) {
            switch (s[i]) {
                case '(':
                    stk.push({i, s[i]});
                    break;
                case ')':
                    if (stk.top().val == '(')
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
    while (!stk.empty()) {
//        cout << stk.top().pos;
        ss.erase(stk.top().pos, 1);
        stk.pop();
    }
    vector<string> result;
    result.emplace_back(ss);


    for (int i = s.size() - 1; i != -1; --i) {
        if (!stk.empty()) {
            switch (s[i]) {
                case '(':
                    stk.push({i, s[i]});
                    break;
                case ')':
                    if (stk.top().val == '(')
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
    while (!stk.empty()) {
//        cout << stk.top().pos;
        sss.erase(stk.top().pos, 1);
        stk.pop();
    }
//    vector<string> result;
    result.emplace_back(sss);
    return result;
}

bool solutions::reorderedPowerOf2(int n) {
    vector<string> uset = {"1", "2", "4", "8", "16", "23", "46", "128", "256", "125", "0124", "0248", "0469", "1289",
                           "13468", "23678", "35566", "011237", "122446", "224588", "0145678", "0122579", "0134449",
                           "0368888", "11266777", "23334455", "01466788", "112234778", "234455668", "012356789",
                           "0112344778"};
    auto s = to_string(n);
    sort(s.begin(), s.end());
    return count(uset.begin(), uset.end(), s);
}

bool solutions::isSelfCrossing(vector<int> &distance) {
    int n = distance.size();
    if (n < 3)
        return false;
    for (int i = 3; i < n; i++) {
        if (distance[i] >= distance[i - 2] && distance[i - 1] <= distance[i - 3])
            return true;
        if (i == 4 && distance[3] == distance[1] && distance[2] >= (distance[4] + distance[0]))
            return true;
        if (i > 4 &&
            distance[i - 3] <= (distance[i - 1] + distance[i - 5]) &&
            distance[i - 1] <= distance[i - 3] &&
            distance[i] >= (distance[i - 2] - distance[i - 4]) &&
            distance[i - 2] > distance[i - 4])
            return true;
    }
    return false;
}

vector<string> solutions::findWords(vector<string> &words) {
    string letters(26, '0');
//string letters="12210111011122000010020202";
    for (auto l: string("asdfghjkl"))
        letters[l - 'a'] = '1';
    for (auto l: string("zxcvbnm"))
        letters[l - 'a'] = '2';

    vector<string> ans;
    for (auto &word: words) {
        char x = letters[tolower(word[0]) - 'a'];
        int isValid = 1;
        for (auto l: word) {
            if (letters[tolower(l) - 'a'] != x) {
                isValid = 0;
                break;
            }
        }
        if (isValid)
            ans.emplace_back(word);
    }
    return ans;
}

int solutions::distributeCandies(vector<int> &candyType) {
//    unordered_map<int, int> Hash;
    return min(unordered_set<int>(candyType.begin(), candyType.end()).size(), candyType.size() / 2);

    return 0;
}

int solutions::maxArea(vector<int> &height) {
    int maxArea = 0;
    int left = 0, right = height.size() - 1;
    while (left < right) {
        maxArea = max(maxArea, min(height[left], height[right]) * (right - left));
        if (height[left] < height[right])
            ++left;
        else
            --right;
    }
    return maxArea;
}

int solutions::trap(vector<int> &height) {
    // 1. dp
    int n = height.size();
    if (n < 3)
        return 0;
    vector<int> leftMax(n, 0), rightMax(n, 0);
//    leftMax[0]=0;
//    rightMax[n-1]=0;
    for (int i = 1; i < n; ++i) {
        // update leftMax
        leftMax[i] = height[i - 1] > leftMax[i - 1] ? height[i - 1] : leftMax[i - 1];
        // update rightMax
        rightMax[n - i - 1] = height[n - i] > rightMax[n - i] ? height[n - i] : rightMax[n - i];
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int sub = (leftMax[i] < rightMax[i] ? leftMax[i] : rightMax[i]);
        if (sub > height[i])
            ans += (sub - height[i]);
    }
    return ans;
}


int solutions::longestSubsequence(vector<int> &arr, int difference) {
//    int n=arr.size();
//    if (n==1)
    return 1;
    // 令 dp[i]表示以 arr[i] 为结尾的最长的等差子序列的长度

}

int solutions::missingNumber(vector<int> &nums) {
//    int n=nums.size();
//    unordered_set<int> miss;
//    for (auto k:nums) {
//        miss.insert(k);
//    }
//    for (int i = 0; i <= n; ++i) {
//        if (miss.count(i)==0)
//            return i;
//    }
//    return 0;
    int n = nums.size();
    int sum = 0;
    for (int k: nums) {
        sum += k;
    }
    return n * (n + 1) / 2 - sum;
}

int solutions::maxCount(int m, int n, vector<vector<int>> &ops) {
    int numOp = ops.size();
    int minA = m, minB = n;
    for (int i = 0; i < numOp; ++i) {
        if (ops[i][0] < minA)
            minA = ops[i][0];
        if (ops[i][1] < minB)
            minB = ops[i][1];
    }
    return minA * minB;
}

string solutions::getHint(string secret, string guess) {
    int bulls = 0;
    vector<int> cntS(10), cntG(10);
    for (int i = 0; i < secret.length(); ++i) {
        if (secret[i] == guess[i]) {
            ++bulls;
        } else {
            ++cntS[secret[i] - '0'];
            ++cntG[guess[i] - '0'];
        }
    }
    int cows = 0;
    for (int i = 0; i < 10; ++i) {
        cows += min(cntS[i], cntG[i]);
    }
    return to_string(bulls) + "A" + to_string(cows) + "B";
}

int solutions::findPoisonedDuration(vector<int> &timeSeries, int duration) {
    int n = timeSeries.size();
    int ans = duration;
    for (int i = 1; i < n; ++i) {
        ans += duration;
        if (timeSeries[i] - timeSeries[i - 1] < duration)
            ans -= (duration - timeSeries[i] + timeSeries[i - 1]);
    }
    return ans;
}

int solutions::getMoneyAmount(int n) {

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = n - 1; i >= 1; --i) {
        for (int j = i + 1; j <= n; ++j) {
            // 循环
            int subMin = INT_MAX;
            for (int k = i; k < j; k++) {
                int con = k + max(dp[i][k - 1], dp[k + 1][j]);
                if (con < subMin)
                    subMin = k + max(dp[i][k - 1], dp[k + 1][j]);
            }
            dp[i][j] = subMin;
            cout << i << "\t" << j << "\t" << dp[i][j] << endl;
        }
    }
    return dp[1][n];
}

bool solutions::detectCapitalUse(string word) {
    bool ans = true;
    int length = word.size();
    if (length == 1)
        return true;
    for (auto c: word) {
        ans *= isupper(c);
    }
    if (ans)
        return ans;
    for (int i = 1; i < length; ++i) {
        if (isupper(word[i]))
            return false;
    }
    return true;
}

bool solutions::isRectangleCover(vector<vector<int>> &rectangles) {
    typedef pair<int, int> Point;
    // 找出大矩阵
    int leftX = rectangles[0][0], leftY = rectangles[0][1], rightX = rectangles[0][2], rightY = rectangles[0][3];
    int sumArea = 0;
    map<Point, int> cnt;

    for (auto s: rectangles) {
        Point point1({s[0], s[1]});
        Point point2({s[0], s[3]});
        Point point3({s[2], s[1]});
        Point point4({s[2], s[3]});
        cnt[point1]++;
        cnt[point2]++;
        cnt[point3]++;
        cnt[point4]++;

        sumArea += (s[3] - s[1]) * (s[2] - s[0]);
        cout << sumArea << endl;
//        cnt.insert()
        if (s[0] < leftX)
            leftX = s[0];
        if (s[1] < leftY)
            leftY = s[1];
        if (s[2] > rightX)
            rightX = s[2];
        if (s[3] > rightY)
            rightY = s[3];
    }
    Point point11({leftX, leftY});
    Point point12({leftX, rightY});
    Point point21({rightX, rightY});
    Point point22({rightX, leftY});

    if ((rightY - leftY) * (rightX - leftX) != sumArea || !cnt.count(point11) || !cnt.count(point12) ||
        !cnt.count(point21) || !cnt.count(point22))
        return false;
    cnt.erase(point11);
    cnt.erase(point12);
    cnt.erase(point21);
    cnt.erase(point22);
    for (auto &s: cnt) {
        int value = s.second;
        if (value != 2 && value != 4)
            return false;
    }
    return true;
}

int solutions::maxProduct(vector<string> &words) {
    int n = words.size();
    int ans = 0;
    vector<int> masks(n, 0);
    for (int i = 0; i < n; ++i) {
        for (auto c: words[i]) {
            masks[i] |= 1 << (c - 'a');
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            ans = max(ans, int(words[i].size() * words[j].size()));
        }
    }
    return ans;
}

int solutions::isCover(string &basicString, string &basicString1) {
    int m = basicString.size(), n = basicString1.size();
    unordered_set<char> s1;
    for (auto c: basicString) {
        s1.insert(c);
    }
    for (auto c: basicString1) {
        if (s1.count(c))
            return -1;
    }
    return m * n;
}


int solutions::integerReplacement(int n) {
    if (n == 1)
        return 0;
    if (n == INT_MAX)
        return 32;
    if (n & 1)
        return 1 + min(integerReplacement(n - 1), integerReplacement(n + 1));
    else
        return integerReplacement(n / 2) + 1;
}

int solutions::findLHS(vector<int> &nums) {
    unordered_map<int, int> cnt;
    for (int i: nums) {
        cnt[i]++;
    }
    int lhs = 0;
    for (auto[key, val]: cnt) {
        if (cnt.count(key + 1))
            lhs = max(cnt[key + 1] + val, lhs);
    }
    return lhs;
}

vector<int> solutions::serialize(TreeNode *root) {
    if (!root)
        return {};
    vector<int> ans;
    queue<TreeNode *> q;
    q.push(root);
    int null = 1001;
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        ans.push_back(curr->val);
        if (curr->left)
            q.push(curr->left);
        else
            ans.emplace_back(null);
        if (curr->right)
            q.push(curr->right);
        else
            ans.emplace_back(null);
    }
    return ans;
}

TreeNode *solutions::deserialize(vector<int> data) {
    if (data.empty())
        return nullptr;
    for (int i = 1; i < data.size() + 1; ++i) {
        if (data[i - 1] != 1001)
            auto tmp = new TreeNode(data[i - 1]);
    }
    return nullptr;
}

bool solutions::buddyStrings(string s, string goal) {
    if (s.size() != goal.size())
        return false;
    int dif = 0;
    unordered_map<char, int> cnt1, cnt2;
    for (int i = 0; i < s.size(); ++i) {
        cnt1[s[i]]++;
        cnt2[goal[i]]++;
        if (s[i] != goal[i])
            dif++;
    }
    if (dif == 2 && cnt1 == cnt2)
        return true;
    for (auto[key, cnt]: cnt1) {
        if (cnt > 1 && cnt2[key] > 1 && dif == 0)
            return true;
    }
    return false;
}

void solutions::solveSudoku(vector<vector<char>> &board) {

}

vector<int> solutions::findAnagrams(string s, string p) {
    // 烂尾待续
    vector<int> cnt(26, 0);
    vector<int> ans;
    int length = p.size();
    for (auto c: p) {
        cnt[c - 'a']++;
    }
    vector<int> tmp;

    for (int i = 0; i < s.size(); ++i) {
        if (cnt[s[i] - 'a']) {
            if (tmp.empty()) {
                tmp.resize(26, 0);
                for (int j = i; j < length + i && j < s.size(); ++j) {
                    if (cnt[s[j] - 'a'] == 0) {
                        i = j;
                        tmp.clear();
                        break;
                    } else {
                        tmp[s[j] - 'a']++;
                    }
                }
            } else {
                tmp[s[i] - 'a']++;
                tmp[s[i - 1] - 'a']--;
            }
            if (tmp == cnt)
                ans.emplace_back(i);
        }
    }

    return ans;
}

vector<int> solutions::maxSumOfThreeSubarrays(vector<int> &nums, int k) {
    int n = nums.size();
    int sum1 = 0, sum2 = 0, sum3 = 0;
    int Idx1 = 0, Idx11 = 0, Idx12 = 0, Idx3;
    int max1 = 0, max2 = 0, max3 = 0;
    vector<int> ans;
    for (int i = 2 * k; i < n; ++i) {
        sum1 += nums[i - 2 * k];
        sum2 += nums[i - k];
        sum3 += nums[i];
        if (i > 3 * k - 2) {
            if (sum1 > max1) {
                Idx1 = i - 3 * k + 1;
                max1 = sum1;
            }
            if (max1 + sum2 > max2) {
                Idx11 = Idx1;
                Idx12 = i - 2 * k + 1;
                max2 = max1 + sum2;
            }
            if (max2 + sum3 > max3) {
                Idx3 = i - k + 1;
                max3 = max2 + sum3;
                ans = {Idx11, Idx12, Idx3};
            }
            sum1 -= nums[i - 3 * k + 1];
            sum2 -= nums[i - 2 * k + 1];
            sum3 -= nums[i - k + 1];
        }
    }
    return ans;
}

string solutions::shortestCompletingWord(string licensePlate, vector<string> &words) {
    unordered_map<char, int> cnt;
    for (auto c: licensePlate) {
        if (islower(c)) {
            cnt[c]++;
        }
        if (isupper(c)) {
            cnt[(char) tolower(c)]++;
        }
    }
    string ans;
    for (auto word: words) {

    }
    return ans;
}

int solutions::maxIncreaseKeepingSkyline(vector<vector<int>> &grid) {
    int row = grid.size(), col = grid[0].size();
    vector<int> rowM(row, 0), colM(col, 0);
    int tmp = 0;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            tmp = max(tmp, grid[i][j]);
        }
        rowM[i] = tmp;
        tmp = 0;
    }
    for (int i = 0; i < col; ++i) {
        for (int j = 0; j < row; ++j) {
            tmp = max(tmp, grid[j][i]);
        }
        colM[i] = tmp;
        tmp = 0;
    }
    int ans = 0;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            tmp = min(rowM[i], colM[j]) - grid[i][j];
            if (tmp > 0)
                ans += tmp;
        }
    }
    return ans;
}

int solutions::visiblePoints(vector<vector<int>> &points, int angle, vector<int> &location) {
    vector<double> angles;
    double k = 180.0 / 3.14159;
    int flag = 0;
    for (auto pos: points) {
        if (pos == location) {
            flag++;
            continue;
        }
        auto a = atan2((pos[1] - location[1]), (pos[0] - location[0])) * k;
        angles.emplace_back(a);
    }
    std::sort(angles.begin(), angles.end());
    int n = angles.size();
    for (int i = 0; i < n; ++i) {
        if (angles[i] + 360 - angles[n - 1] <= angle)
            angles.push_back(angles[i] + 360);
        else
            break;
    }
    int ans = 0, cur = 0;
    int end = 0;

    for (int i = 0; i < angles.size(); ++i) {
        while (end < angles.size() && angles[end] <= angles[i] + angle) {
            end++;
        }
        ans = max(ans, end - i);
    }
    return ans + flag;


//    int sameCnt = 0;
//    vector<double> polarDegrees;
//    for (auto & point : points) {
//        if (point[0] == location[0] && point[1] == location[1]) {
//            sameCnt++;
//            continue;
//        }
//        double degree = atan2(point[1] - location[1], point[0] - location[0]);
//        polarDegrees.emplace_back(degree);
//    }
//    sort(polarDegrees.begin(), polarDegrees.end());
//
//    int m = polarDegrees.size();
//    for (int i = 0; i < m; ++i) {
//        polarDegrees.emplace_back(polarDegrees[i] + 2 * M_PI);
//    }
//
//    int maxCnt = 0;
//    int right = 0;
//    double degree = angle * M_PI / 180;
//    for (int i = 0; i < m; ++i) {
//        while (right < polarDegrees.size() && polarDegrees[right] <= polarDegrees[i] + degree) {
//            right++;
//        }
//        maxCnt = max(maxCnt, right - i);
//    }
//    return maxCnt + sameCnt;
}

int solutions::countBattleships(vector<vector<char>> &board) {
    int cnt = 0;

    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            if (board[i][j] == 'X')
                bfs(i, j, board, cnt);
        }
    }
    return cnt;
}

void solutions::bfs(int i, int j, vector<vector<char>> &board, int &cnt) {
    if (board[i][j] == 'v')
        return;
    if (board[i][j] == 'X') {
        cnt++;
        if (j < board[0].size() - 1 && board[i][j + 1] == 'X') {
            vertical(i, j, board);
        } else if (i < board.size() - 1 && board[i + 1][j] == 'X') {
            horizontal(i, j, board);
        }
    }
}

void solutions::vertical(int i, int j, vector<vector<char>> &board) {
    if (j == board[0].size())
        return;
    if (board[i][j] == 'X') {
        board[i][j] = 'v';
        vertical(i, j + 1, board);
    } else
        return;
}

void solutions::horizontal(int i, int j, vector<vector<char>> &board) {
    if (i == board.size())
        return;
    if (board[i][j] == 'X') {
        board[i][j] = 'v';
        horizontal(i + 1, j, board);
    } else
        return;
}

bool solutions::repeatedSubstringPattern(string s) {
    return (s + s).find(s, 1) != s.size();
}

int solutions::repeatedStringMatch(string a, string b) {
//        int strStr(string &haystack, string &needle) {
//            int n = haystack.size(), m = needle.size();
//            if (m == 0) {
//                return 0;
//            }
//            vector<int> pi(m);
//            for (int i = 1, j = 0; i < m; i++) {
//                while (j > 0 && needle[i] != needle[j]) {
//                    j = pi[j - 1];
//                }
//                if (needle[i] == needle[j]) {
//                    j++;
//                }
//                pi[i] = j;
//            }
//            for (int i = 0, j = 0; i - j < n; i++) { // b 开始匹配的位置是否超过第一个叠加的 a
//                while (j > 0 && haystack[i % n] != needle[j]) { // haystack 是循环叠加的字符串，所以取 i % n
//                    j = pi[j - 1];
//                }
//                if (haystack[i % n] == needle[j]) {
//                    j++;
//                }
//                if (j == m) {
//                    return i - m + 1;
//                }
//            }
//            return -1;
//        }

//        int repeatedStringMatch(string a, string b) {
//            int an = a.size(), bn = b.size();
//            int index = strStr(a, b);
//            if (index == -1) {
//                return -1;
//            }
//            if (an - index >= bn) {
//                return 1;
//            }
//            return (bn + index - an - 1) / an + 2;
//        }
//    };
}

int solutions::kmp(string haystack, string needle) {
    // compare string using kmp
    // haystack: target
    // needle: pattern
    if (needle.empty())
        return 0;
    vector<int> next(needle.size(), 0);


    for (int i = 0; i < needle.size(); ++i) {
        string tmp = needle.substr(0, i + 1);
        for (int j = 0; j < (i + 1) / 2; ++j) {
            if (tmp[j] == tmp[(i - j)])
                next[i]++;
            else
                break;
        }
    }


    int ret = 0, maxN;
    for (int i = 0, j = 0; i < haystack.size(); ++i, ++j) {
        if (haystack[i] != needle[j]) {
            if (j == 0){
                ret++;
                j--;
            }
            else {
                maxN = *max_element(next.begin(), next.begin() + i);
                ret += maxN;
                j = maxN - 1;
                i--;
            }
        } else {
            if (j == needle.size() - 1)
                return ret;
        }
    }
    return -1;
}


struct cla {
    int n;
    int pre;
};

//bool solutions::canFinish(int numCourses, vector<vector<int>> &prerequisites) {
//    unordered_set<cla> preq;
//    for (auto p:prerequisites) {
//        preq.insert(pair<p[0],p[1]>);
//    }
//    vector<int> visited(numCourses, 0);
//    unordered_set<int> visiting;
//    bool ans= true;
//    for (int i = 0; i < numCourses; ++i) {
//        if (visited[i] == 0){
//            ans = dfs(i, numCourses, visited,visiting, prerequisites);
//        }
//    }
//    if (!ans)
//        return false;
//    for (int i = 0; i < numCourses; ++i) {
//        if (visited[i] == 0)
//            return false;
//    }
//    return true;
//}
//
//bool solutions::dfs(int i, int courses, vector<int> &visited,unordered_set<int> &visiting, vector<vector<int>> &prerequisites) {
//    if (visited[i] == 1)
//        return true;
//    visiting.insert(i);
//    int p = INT_MAX;
//    for () {
//        if (xx[0]==i){
//                p = xx[1];
//                if (visiting.count(p)){
//                    return false;
//                }
//                if (visited[p] == 1)
//                    visited[i] = 1;
//                else{
//                    auto x=dfs(p, courses, visited,visiting, prerequisites);
//                    if (!x)
//                        return false;
//                    else{
//                        prerequisites.erase()
//                    }
//                }
//        }
//    }
//    visited[i] = 1;
//    visiting.erase(i);
//    return true;
//}



int solutions::getN(int k) {
    int i = 0;
    for (; i < k; i++) {
        if ((i + 1) * i / 2 <= k && (i + 2) * (i + 1) / 2 >= k)
            return ++i;
    }
    return 0;
}

vector<int> solutions::kthSmallestPrimeFraction(vector<int> &arr, int k) {
    int i = getN(k);
    int n = arr.size();
    int x = k - (i - 1) * i / 2;
    map<float, pair<int, int>> ans;
    for (int j = 0; j < i; j++) {
        ans[float(arr[j]) / float(arr[n + j -i])] = {arr[j], arr[n + j -i]};
    }
    auto it = ans.begin();
    for (int j = 1; j < x; ++j) {
        it++;
    }
    return {it->second.first, it->second.second};
}

int solutions::findNthDigit(int n) {
    int i=0;
    for (; i < 9; ++i) {
//cout<< i << ":  "<<findLength(i)<<"\n";
        if (n>= findLength(i) && n <= findLength(i+1))
            break;
    }

    // 具体的数字
    int x = findLength(i);
    int base= pow(10, i);
    int index = ceil(float (n- x)/(i+1))+ base -1;
    // 在数字的第几位
    int diff = (n- x-(index- base)*(i+1));
    string indexS = to_string(index);
    return (indexS[diff-1]-'0');
}

int solutions::findLength(int n) {
    if (n==0)
        return 0;
    if (n==9)
        return INT_MAX;
    // 返回数n的第一个数字的位置
    int cnt=1;
    long length=0;
    while (n--){
        length+=((pow(10, cnt)- pow(10,(cnt-1)))*cnt++);
    }
    return length;
}

int solutions::findMinStep(string board, string hand) {
    // BFS
    // not cut first
    queue<pair<string, string>> q;
    q.push({board, hand});
    int ans=0;
    while (!q.empty()){
        int length = q.size();
        ans++;
        for (int i = 0; i < length; ++i) {
            auto [bod, had] = q.front();
            q.pop();
            for (int j = 0; j < bod.size(); ++j) {
                for (int k = 0; k < had.size(); ++k) {
                    bod.insert(i,1,had[k]);
                    adapt(bod);
                }
            }
        }
    }
    return 0;
}

void solutions::adapt(string s) {
    int cnt=0;
    char tmp=s[0];
    for (int i = 0; i < s.size(); ++i) {
        if (s[i]==tmp)
            cnt++;
        else{
            cnt=1;
            tmp=s[i];

        }
    }
}

