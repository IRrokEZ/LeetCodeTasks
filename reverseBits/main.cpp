#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <bitset>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
// 190. Reverse Bits
        uint32_t reverseBits(uint32_t n) {
            std::string str = "";
            while (n > 0) {
                str += (((n % 2) == 1)? "1":"0");
                n /= 2;
            }
            str.resize(32, '0');
            std::reverse(str.begin(), str.end());
            uint32_t result = 0, multer = 1;
            for (const char s : str) {
                if (s == '1') {
                    result += multer;
                }
                multer *= uint32_t(2);
            }
            return result;
        }
// 191. Number of 1 Bits
        int hammingWeight(int n) {
            int result = 0;
            while (n > 0) {
                if ((n % 2) == 1) {
                    ++ result;
                }
                n /= 2;
            }
            return result;
        }
// 202. Happy Number
        bool isHappy(int64_t n) {
            std::set <int64_t> square_sums;
            int64_t wrk = n, sum;
            bool is_happy = false;
            while (!is_happy) {
                sum = 0;
                while(wrk != 0) {
                    int dig = wrk % 10;
                    sum += dig * dig;
                    wrk /= 10;
                }
                if (sum == 1) {
                    return true;
                }
                if (square_sums.count(sum) == 1) {
                    return false;
                } else {
                    square_sums.insert(sum);
                }
                wrk = sum;
            }
            return true;
        }
// 203. Remove Linked List Elements
        ListNode* removeElements(ListNode* head, int value) {
            if (head == nullptr) {
                return nullptr;
            }
            if ((head->next == nullptr) && (head->val == value)) {
                return nullptr;
            }

            ListNode *save, *previous;
            if (head->val == value) {
                save = nullptr;
            } else {
                save = head;
            }
            head = head->next;
            previous = save;
            while (head != nullptr) {
                if (head->val == value) {
                    if (previous != nullptr) {
                        previous->next = head->next;
                    }
                    head = head->next;
                } else {
                    if (previous == nullptr) {
                        save = head;
                    }
                    previous = head;
                    head = head->next;
                }
            }
            return save;
        }
// 205. Isomorphic Strings
    bool isIsomorphic(std::string s, std::string t) {
        std::set<char> ss(s.begin(), s.end()), tt(t.begin(), t.end());
        if (ss.size() != tt.size()) {
            return false;
        }
        ss.clear();
        tt.clear();
        std::map<size_t, std::vector<size_t>/*id list*/> s_symbols, t_symbols;
        std::map<char, size_t> s_ids, t_ids;
        for (size_t i = 0; i < s.size(); ++ i) {
            if (s_ids[s[i]] == 0) {
                s_ids[s[i]] = i + 1;
            }
            if (t_ids[t[i]] == 0) {
                t_ids[t[i]] = i + 1;
            }
            s_symbols[s_ids[s[i]]].push_back(i);
            t_symbols[t_ids[t[i]]].push_back(i);
            if (s_symbols[s_ids[s[i]]].size() != t_symbols[s_ids[s[i]]].size()) {
                return false;
            }
        }
        for (const auto [key, value] : s_symbols) {
            if (!std::equal(s_symbols[key].begin(), s_symbols[key].end(), t_symbols[key].begin())) {
                return false;
            }
        }
        return true;
    }
// 217. Contains Duplicate
    //first answer
    bool containsDuplicate1(std::vector<int>& nums) {
        std::set<int> num (nums.begin(), nums.end());
        return (num.size() != nums.size());
    }
    // second answer - slower
    bool containsDuplicate2(std::vector<int>& nums) {
        std::map<int, int> num;
        for (const int val : nums) {
            ++ num[val];
            if (num[val] > 1) {
                return true;
            }
        }
        return false;
    }
    // third answer - faster
    bool containsDuplicate3(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size() - 1; ++ i) {
            if (nums[i] == nums[i + 1]) {
                return true;
            }
        }
        return false;
    }
// 228 Summary Ranges
    std::vector<std::string> summaryRanges(std::vector<int> &nums) {
        if (nums.empty()) {
            return {};
        }
        std::vector<std::string> result;
        std::string wrk = "";
        int64_t left, right;
        for (size_t i = 0; i < nums.size(); ++ i) {
            if (wrk.empty()) {
                left = nums[i];
                right = left;
                wrk += std::to_string(left);
                continue;
            }
            if ((nums[i] - right) == 1) {
                ++right;
                continue;
            }
            if ((nums[i] - right) > 1) {
                if (right != left) {
                    wrk += "->" + std::to_string(right);
                }
                result.push_back(wrk);
                left = nums[i];
                right = left;
                wrk = std::to_string(left);
            }
        }
        if (right != left) {
            wrk += "->" + std::to_string(right);
        }
        result.push_back(wrk);
        return result;
    }
// 231. Power of Two
    bool isPowerOfTwo(int64_t n) {
        if (n <= 0) {
            return false;
        }
        std::string binary_number = std::bitset<32>(n).to_string();
        return (std::count(binary_number.begin(), binary_number.end(), '1') == 1);
    }
    bool isPowerOfTwo2(int64_t n) {
        if (n <= 0) {
            return false;
        }
        return (std::bitset<32>(n).count() == 1);
    }
    bool isPowerOfTwo3(int64_t n) {
        return (n > 0) && ((n & (n - 1)) == 0);
    }
// 242. Valid Anagram
    // curr
    bool isAnagram(const std::string &s, const std::string &t) {
        if (s.size() != t.size()) {
            return false;
        }
        std::vector<int> decomp (26, 0);
        for (char c : s) {
            ++ decomp[c - 'a'];
        }
        for (char c : t) {
            -- decomp[c - 'a'];
            if (decomp[c - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
    // general
    bool isAnagram2(const std::string &s, const std::string &t) {
        if (s.size() != t.size()) {
            return false;
        }
        std::vector<int> decomp (256, 0);
        for (char c : s) {
            ++ decomp[int(c)];
        }
        for (char c : t) {
            -- decomp[int(c)];
            if (decomp[int(c)] < 0) {
                return false;
            }
        }
        return true;
    }
// 70. Climbing Stairs
    int climbStairs(int n) {
        if ((n == 1) || (n == 2)) {
            return n;
        }
        int prev = 1, curr = 2, tmp;
        for (int i = 3; i <= n; ++ i) {
            tmp = curr;
            curr = prev + curr;
            prev = tmp;
        }
        return curr;
    }
// 258. Add Digits
    int addDigits(int num) {
        int tmp = 0;
        while (num > 9) {
            tmp = num;
            num = 0;
            while (tmp > 0) {
                num += tmp % 10;
                tmp /= 10;
            }
        }
        return num;
    }
    // fastest
    int addDigits2(int num) {
        if (num == 0) {
            return 0;
        }
        if ((num % 9) == 0) {
            return 9;
        }
        return num % 9;
    }
// 263. Ugly Number
    bool isUgly(int n) {
        if (n == 0) {
            return false;
        }
        if (n == 1) {
            return true;
        }
        while ((n % 2) == 0) {
            n /= 2;
        }
        if (n == 1) {
            return true;
        }
        while ((n % 3) == 0) {
            n /= 3;
        }
        if (n == 1) {
            return true;
        }
        while ((n % 5) == 0) {
            n /= 5;
        }
        if (n == 1) {
            return true;
        }
        return false;
    }
// 268. Missing Number
    int missingNumber(const std::vector<int>& nums) {
        int64_t TwoSumms = nums.size() * (nums.size() + 1) / 2;
        for (int a : nums) {
            TwoSumms -= a;
        }
        return TwoSumms;
    }
};

int main() {
    Solution solution;
    return 0;
}
