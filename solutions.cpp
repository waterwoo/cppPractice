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
                tmp[s[i-1] - 'a']--;
            }
            if (tmp == cnt)
                ans.emplace_back(i);
        }
    }

    return ans;
}

