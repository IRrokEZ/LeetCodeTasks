#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 303. Range Sum Query - Immutable
class NumArray {
private:
    std::vector<int> values;
    std::vector<int> sums;
public:
    NumArray(std::vector<int>& nums) {
        values.resize(nums.size());
        sums.resize(nums.size());
        for (size_t i = 0; i < nums.size(); ++ i) {
            values[i] = nums[i];
            sums[i] = nums[i];
            if (i != 0) {
                sums[i] += sums[i - 1];
            }
        }
    }

    int sumRange(int left, int right) {
        size_t l = left, r = right;
        if (l == 0) {
            return sums[r];
        }
        return (sums[r] - sums[l - 1]);
    }
};

class Solution {
    public:
// 1. Two Sum
    std::vector<int> twoSum (std::vector<int> &nums, int target) {
        std::unordered_map <int, int> visited;
        for (size_t i = 0; i < nums.size(); i ++) {
            int complement = target - nums[i];
            if (visited.count(complement)) {
                return {visited[complement], int(i)};
            }
            visited[nums[i]] = int(i);
        }
        return {};
    }
// 9. Palindrome Number
    bool isPalindrome (int x) {
        if (x < 0) {
            return false;
        }
        int64_t rev_x = 0, corr_x = x;
        for ( ; corr_x > 0; ) {
            rev_x *= 10;
            rev_x += corr_x % 10;
            corr_x /= 10;
        }
        return x == rev_x;
    }
// 13. Roman to Integer
    int convertSymbToInt (char c) {
        switch (c) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
        }
        return 0;
    }
    int romanToInt (std::string s) {
        int rez = 0;
        for (size_t i = 0; i < s.size(); i ++) {
            int a = convertSymbToInt(s[i]);
            int b;
            if(i + 1 >= s.size()) {
                b = -1;
            } else {
                b = convertSymbToInt(s[i + 1]);
            }
            if (a < b) {
                rez += b - a;
                i ++;
            }  else {
                rez += a;
            }
        }
        return rez;
    }
// 14. Longest Common Prefix
    std::string longestCommonPrefix (std::vector<std::string>& strs) {
        if (strs.size() == 1) {
            return strs[0];
        }
        std::string first = strs[0], pref = "";
        bool pref_fin = false;
        for (size_t i = 1; i < strs.size(); ++ i) {
            if ((pref.empty()) && !pref_fin) {
                pref_fin = true;
                for (size_t j = 0; (j < strs[i].size() && j < first.size()); ++ j) {
                    if (first[j] == strs[i][j]) {
                        pref += first[j];
                    } else {
                        break;
                    }
                }
            } else {
                if (strs[i].empty()) {
                    return "";
                }
                size_t j;
                for (j = 0; (j < strs[i].size() && j < pref.size()); ++ j) {
                    if (pref[j] != strs[i][j]) {
                        pref.erase(pref.begin() + j, pref.end());
                        if (pref.empty()) {
                            return "";
                        }
                    }
                }
                if (j < pref.size()) {
                    pref.erase(pref.begin() + j, pref.end());
                }
            }
        }
        return pref;
    }
// 20. Valid Parentheses
    bool isValid (std::string s) {
        std::deque<char> brackets;
        std::map<char, char> brackets_pairs;
        brackets_pairs['}'] = '{';
        brackets_pairs[']'] = '[';
        brackets_pairs[')'] = '(';
        std::set<char> open_brackets {'(', '[', '{'}, close_brackets {')', ']', '}'};
        for (size_t i = 0; i < s.size(); ++ i) {
            if (open_brackets.find(s[i]) != open_brackets.end()) {
                brackets.push_back(s[i]);
            } else if (close_brackets.find(s[i]) != close_brackets.end()) {
                if (brackets.empty() || (brackets.back() != brackets_pairs[s[i]])) {
                    return false;
                } else {
                    brackets.pop_back();
                }
            }
        }
        return brackets.empty();
    }
// 21. Merge Two Sorted Lists
    ListNode* mergeTwoLists (ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }

        ListNode* wrk;
        ListNode* save_list1 = list1;
        ListNode* save_list2 = list2;

        if (save_list1->val < save_list2->val) {
            wrk = new ListNode(save_list1->val);
            save_list1 = save_list1->next;
        } else {
            wrk = new ListNode(save_list2->val);
            save_list2 = save_list2->next;
        }

        ListNode* result = wrk;

        while ((save_list1 != nullptr) && (save_list2 != nullptr)) {
            if (save_list1->val < save_list2->val) {
                wrk->next = new ListNode(save_list1->val);
                save_list1 = save_list1->next;
            } else {
                wrk->next = new ListNode(save_list2->val);
                save_list2 = save_list2->next;
            }
            wrk = wrk->next;
        }

        if (save_list1 != nullptr) {
            wrk->next = new ListNode(save_list1->val, save_list1->next);
        } else if (save_list2 != nullptr) {
            wrk->next = new ListNode(save_list2->val, save_list2->next);
        }
        return result;
    }
// 26. Remove Duplicates from Sorted Array
    int removeDuplicates (std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        std::vector<int> copy(nums.size());
        copy[0] = nums[0];
        int k = 1;
        for (size_t i = 1; i < nums.size(); ++ i) {
            if (nums[i - 1] != nums[i]) {
                copy[k] = nums[i];
                ++ k;
            }
        }
        nums = copy;
        return k;
    }
// 27. Remove Element
    int removeElement (std::vector<int>& nums, int val) {
        std::vector<int> cpy(nums.size());
        size_t j = 0;
        for (size_t i = 0; i < nums.size(); ++ i) {
            if (nums[i] != val) {
                cpy[j] = nums[i];
                ++ j;
            }
        }
        nums = cpy;
        return j;
    }
// 28. Find the Index of the First Occurrence in a String
    int strStr (std::string haystack, std::string needle) {
        if (needle.size() > haystack.size()) {
            return -1;
        }
        int result = -1;
        for (size_t i = 0; i < haystack.size(); ++ i) {
            if (haystack[i] == needle[0]) {
                result = i;
                for(size_t j = 0; j < needle.size(); ++ j) {
                    if (haystack[i + j] != needle[j]) {
                        result = -1;
                        break;
                    }
                }
                if (result >= 0) {
                    return result;
                }
            }
        }
        return result;
    }
// 35. Search Insert Position
    int searchInsert (std::vector<int>& nums, int target) {
        size_t sz = nums.size();
        size_t beg = 0, mid = sz / 2, last = sz - 1;
        if (target <= nums[0]) {
            return 0;
        }
        if (target > nums[last]) {
            return (last + 1);
        }
        for( ; (last - beg) > 1 ; ) {
            if (target > nums[mid]) {
                beg = mid;
            } else {
                last = mid;
            }
            mid = (last + beg) / 2;
        }
        if (target <= nums[beg]) {
            return beg;
        }
        if ((target > nums[beg]) && (target <= nums[last])) {
            return last;
        }
        return (last + 1);
    }
// 58. Length of Last Word
    int lengthOfLastWord (std::string s) {
        int lett_counter = 0, save_value = 0;
        for (size_t i = 0; i < s.size(); ++ i) {
            if (s[i] == ' ') {
                if (lett_counter != 0) {
                    save_value = lett_counter;
                }
                lett_counter = 0;
                continue;
            }
            ++ lett_counter;
        }
        if (lett_counter == 0) {
            if (save_value != 0) {
                return save_value;
            }
        }
        return lett_counter;
    }
// 66. Plus One
    std::vector<int> plusOne (std::vector<int>& digits) {
        std::vector<int> newNum((digits.size() + 1));
        int div = 0, mod = -1, r;
        for (size_t i = digits.size(); i > 0; -- i) {
            r = div + digits[i - 1] + ((mod == -1) ? 1 : 0);
            mod = r % 10;
            newNum[i] = mod;
            div = r / 10;
        }
        if (div != 0) {
            newNum[0] = div;
        } else {
            newNum.erase(newNum.begin());
        }
        return newNum;
    }
// 67. Add Binary
    int BinaryCharToInt (char sym) {
        return (sym == '1')? 1 : 0;
    }
    char BinaryIntToChar (int num) {
        return (num == 1)? '1' : '0';
    }
    std::string addBinary (std::string a, std::string b) {
        std::string max_num, min_num;
        size_t max_sz, min_sz;
        if (a.size() > b.size()) {
            max_num = a;
            max_sz = a.size();
            min_num = b;
            min_sz = b.size();
        } else {
            min_num = a;
            min_sz = a.size();
            max_num = b;
            max_sz = b.size();
        }
        int div = 0, mod = -1, r;
        std::string res;
        res.insert(res.begin(), max_sz + 1, '0');
        for (size_t i = 1; i <= max_sz; ++ i) {
            if (min_sz >= i) {
                r = BinaryCharToInt(min_num[min_sz - i]) +
                    BinaryCharToInt(max_num[max_sz - i]) +
                    div;
            } else {
                r = BinaryCharToInt(max_num[max_sz - i]) +
                    div;
            }
            div = r / 2;
            mod = r % 2;
            res[max_sz + 1 - i] = BinaryIntToChar(mod);
        }
        if (div == 1) {
            res[0] = BinaryIntToChar(div);
        } else {
            res.erase(res.begin());
        }
        return res;
    }
// 69. Sqrt(x)
    int mySqrt (int x) {
        if (x < 2) {
            return x;
        }
        int64_t left = 0, right = x;
        int64_t mid;
        for ( ; left < right; ) {
            mid = (left + right + 1) / 2;

            if (mid * mid <= x) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
// 70. Climbing Stairs
    int climbStairs (int n) {
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
// 83. Remove Duplicates from Sorted List
    ListNode* deleteDuplicates (ListNode* head) {
        if ((head == nullptr) || (head->next == nullptr)){
            return head;
        }
        ListNode* wrk = head;
        while (wrk->next != nullptr) {
            if (wrk->val == wrk->next->val) {
                ListNode* del = wrk->next;
                wrk->next = wrk->next->next;
                delete (del);
            } else {
                wrk = wrk->next;
            }
        }
        return head;
    }
// 88. Merge Sorted Array
    void MergeArrays (std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        if (n == 0){
            return void();
        }
        if (m == 0) {
            for (int i = 0; i < n; i ++) {
                nums1[i] = nums2[i];
            }
            return void();
        }
        std::vector<int> result(m + n);
        size_t num1_ptr = 0, num2_ptr = 0;
        for (size_t i = 0; i < size_t(m + n); ++ i) {
            if (num1_ptr == size_t(m)) {
                result[i] = nums2[num2_ptr];
                ++ num2_ptr;
                continue;
            }
            if (num2_ptr == size_t(n)) {
                result[i] = nums1[num1_ptr];
                ++ num1_ptr;
                continue;
            }
            if (nums1[num1_ptr] < nums2[num2_ptr]){
                result[i] = nums1[num1_ptr];
                ++ num1_ptr;
            } else {
                result[i] = nums2[num2_ptr];
                ++ num2_ptr;
            }
        }
        for (size_t i = 0; i < size_t(m + n); ++ i) {
            nums1[i] = result[i];
        }
        result.clear();
    }
// 100. Same Tree
    bool isSameTree (TreeNode* p, TreeNode* q) {
        if((p == nullptr) && (q == nullptr)) {
            return true;
        }

        if ((p == nullptr) || (q == nullptr)) {
            return false;
        }

        if ((p->left == nullptr) && (q->left == nullptr)
            && (p->right == nullptr) && (q->right == nullptr)) {
            return (p->val == q->val);
        }

        return (p->val == q->val) && isSameTree(p->left, q->left) &&
            isSameTree(p->right, q->right);
    }
// 101. Symmetric Tree
    bool checkSymmetric (TreeNode *lft, TreeNode *rght) {
        if ((lft == nullptr) && (rght == nullptr)) {
            return true;
        }
        if ((lft == nullptr) || (rght == nullptr)) {
            return false;
        }
        bool result = lft->val == rght->val
                && checkSymmetric(lft->left, rght->right)
                && checkSymmetric(lft->right, rght->left);
        return result;
    }
    bool isSymmetric (TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        if ((root->left == nullptr) && (root->right == nullptr)) {
            return true;
        }
        return checkSymmetric(root->left, root->right);
    }
// 104. Maximum Depth of Binary Tree
    int maxDepth (TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
    }
// 118. Pascal's Triangle
    std::vector<std::vector<int>> generate (int numRows) {
        if (numRows == 1) {
            return {{1}};
        }
        if (numRows == 2) {
            return {{1}, {1, 1}};
        }
        std::vector<std::vector<int>> result = {{1}, {1, 1}};
        for (int i = 2; i < numRows; ++ i) {
            std::vector<int> str(i + 1);
            str[0] = 1;
            str[i] = 1;
            for (int j = 1; j < i; ++ j) {
                str[j] = result[i - 1][j - 1] + result[i - 1][j];
            }
            result.push_back(str);
        }
        return result;
    }
// 119. Pascal's Triangle II
    std::vector<int> getRow (int rowIndex) {
        if (rowIndex == 0) {
            return {1};
        }
        if (rowIndex == 1) {
            return {1, 1};
        }
        std::vector<int> prev_row = {1, 1};
        std::vector<int> curr_row;
        for (int i = 2; i <= rowIndex; ++ i) {
            curr_row.resize(i + 1);
            curr_row[0] = 1;
            curr_row[i] = 1;
            for (int j = 1; j < i; ++ j) {
                curr_row[j] = prev_row[j - 1] + prev_row[j];
            }
            prev_row = curr_row;
        }
        return curr_row;
    }
// 121. Best Time to Buy and Sell Stock
    int maxProfit (std::vector<int>& prices) {
        int buy = prices[0];
        int profit = 0;
        for (size_t i = 1; i < prices.size(); ++ i) {
            if (prices[i] < buy) {
                buy = prices[i];
            } else if ((prices[i] - buy) > profit) {
                profit = prices[i] - buy;
            }
        }
        return profit;
    }
// 125. Valid Palindrome
    bool isPalindrome (std::string &s) {
        std::string to_check = "";
        for (char c : s) {
            char sym = tolower(c);
            if (((sym >= 'a') && (sym <= 'z')) || ((sym >= '0') && (sym <= '9'))) {
                to_check += sym;
                continue;
            }
        }
        size_t str_size = to_check.size();
        for (size_t i = 0; i < str_size / 2; ++ i) {
            if (to_check[i] != to_check[str_size - 1 - i]) {
                return false;
            }
        }
        return true;
    }
// 136. Single Number
    int singleNumber(std::vector<int>& nums) {
        int result = nums[0];
        for (size_t i = 1; i < nums.size(); ++ i) {
            result = result xor nums[i];
        }
        return result;
    }
// 168. Excel Sheet Column Title
    std::string convertToTitle(int columnNumber) {
        std::string result;
        while (columnNumber > 0) {
            -- columnNumber;
            char c = 'A' + columnNumber % 26;
            result = c + result;
            columnNumber /= 26;
        }
        return result;
    }
// 169. Majority Element
    int majorityElement(std::vector<int>& nums) {
        int max_id = 0, max = 0;
        std::map<int, int> cntr;
        for (int i : nums) {
            ++ cntr[i];
            if (cntr[i] > max) {
                ++ max;
                max_id = i;
                if (max > int(nums.size()) / 2) {
                    return max_id;
                }
            }
        }
        return max_id;
    }
// 171. Excel Sheet Column Number
    int titleToNumber(std::string columnTitle) {
        long int result = 0, multer = 1;
        std::reverse(columnTitle.begin(), columnTitle.end());
        for (const char c : columnTitle) {
            if (c == 'A') {
                result += 1 * multer;
            } else {
                result += int(c - 'A' + 1) * multer;
            }
            multer *= 26;
        }
        return result;
    }
// 190. Reverse Bits
    uint32_t reverseBits (uint32_t n) {
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
    int hammingWeight (int n) {
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
    bool isHappy (int64_t n) {
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
    ListNode* removeElements (ListNode* head, int value) {
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
    bool isIsomorphic (std::string s, std::string t) {
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
    bool containsDuplicate1 (std::vector<int>& nums) {
        std::set<int> num (nums.begin(), nums.end());
        return (num.size() != nums.size());
    }
    // second answer - slower
    bool containsDuplicate2 (std::vector<int>& nums) {
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
    bool containsDuplicate3 (std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size() - 1; ++ i) {
            if (nums[i] == nums[i + 1]) {
                return true;
            }
        }
        return false;
    }
// 228 Summary Ranges
    std::vector<std::string> summaryRanges (std::vector<int> &nums) {
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
    bool isPowerOfTwo (int64_t n) {
        if (n <= 0) {
            return false;
        }
        std::string binary_number = std::bitset<32>(n).to_string();
        return (std::count(binary_number.begin(), binary_number.end(), '1') == 1);
    }
    bool isPowerOfTwo2 (int64_t n) {
        if (n <= 0) {
            return false;
        }
        return (std::bitset<32>(n).count() == 1);
    }
    bool isPowerOfTwo3 (int64_t n) {
        return (n > 0) && ((n & (n - 1)) == 0);
    }
// 242. Valid Anagram
    // curr
    bool isAnagram (const std::string &s, const std::string &t) {
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
    bool isAnagram2 (const std::string &s, const std::string &t) {
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
// 258. Add Digits
    int addDigits (int num) {
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
    int addDigits2 (int num) {
        if (num == 0) {
            return 0;
        }
        if ((num % 9) == 0) {
            return 9;
        }
        return num % 9;
    }
// 263. Ugly Number
    bool isUgly (int n) {
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
    int missingNumber (const std::vector<int>& nums) {
        int64_t TwoSumms = nums.size() * (nums.size() + 1) / 2;
        for (int a : nums) {
            TwoSumms -= a;
        }
        return TwoSumms;
    }
// 278. First Bad Version
    // stub
    bool isBadVersion (int q) {
        return true;
    }
    // my
    int firstBadVersion (int n) {
        if (n == 1) {
            return 1;
        }
        int64_t start = 1, last = n;
        int64_t mid = (start + last) / 2;
        while (last - start > 1) {
            if (isBadVersion(mid)) {
                last = mid;
            } else {
                start = mid;
            }
            mid = (start + last) / 2;
        }
        if (isBadVersion(start)) {
            return start;
        }
        return last;
    }
    // faster
    int firstBadVersion2 (int n) {
        int start = 1, end = n;
        while(start < end){
            int mid = start + (end - start) / 2;
            bool isBad = isBadVersion(mid);
            if (isBad){
                end = mid;
            } else{
                start = mid +1;
            }
        }
        return start;
    }
// 283. Move Zeroes
    void moveZeroes (std::vector<int>& nums) {
        int zero_count = 0;
        for (size_t i = 0; i < nums.size(); ++ i) {
            if (nums[i] == 0) {
                ++ zero_count;
                continue;
            }
            if (zero_count != 0) {
                nums[i - zero_count] = nums[i];
            }
        }
        if (zero_count == int(nums.size())) {
            return void();
        }
        for (size_t i = nums.size(); (i > 0) && (zero_count > 0); -- i, -- zero_count) {
            nums[i - 1] = 0;
        }
    }
// 290. Word Pattern
    bool wordPattern (std::string pattern, std::string s) {
        std::vector<std::string> words;
        std::string word, wrk = s;
        size_t pos = 0;
        while ((pos = wrk.find(' ')) != std::string::npos) {
            word = wrk.substr(0, pos);
            words.push_back(word);
            wrk.erase(0, pos + 1);
        }
        words.push_back(wrk);
        if (words.size() != pattern.size()) {
            return false;
        }
        wrk.clear();
        std::unordered_map<char, std::string> check_letters;
        std::unordered_map<std::string, char> check_words;
        pos = 0;
        for (size_t i = 0; i < pattern.size(); ++ i) {
            if ((check_letters.find(pattern[i]) == check_letters.end())
                && (check_words.find(words[i]) == check_words.end())) {
                check_letters[pattern[i]] = words[i];
                check_words[words[i]] = pattern[i];
                continue;
            }
            if ( ( (check_letters.find(pattern[i]) == check_letters.end())
                    && (check_words.find(words[i]) != check_words.end()) )
                ||
                 ( (check_letters.find(pattern[i]) != check_letters.end())
                    && (check_words.find(words[i]) == check_words.end()) ) ) {
                return false;
            }
            if (check_words[words[i]] != pattern[i]) {
                return false;
            }
        }
        words.clear();
        check_letters.clear();
        check_words.clear();
        return true;
    }
// 292. Nim Game
    bool canWinNim(int n) {
        if ((n % 4) == 0) {
            return false;
        }
        return true;
    }
// 326. Power of Three
    bool isPowerOfThree(int n) {
        if (n < 1) {
            return false;
        }
        double log_value = log10(n) / log10(3);
        return log_value == int(log_value);
    }
// 342. Power of Four
    bool isPowerOfFour(int n) {
        if (n < 1) {
            return false;
        }
        double log_value = log10(n) / log10(4);
        return log_value == int(log_value);
    }
// 344. Reverse String
    void reverseString(std::vector<char>& s) {
        size_t ssize = s.size();
        for (size_t i = 0; i < ssize / 2; ++ i) {
            char save = s[i];
            s[i] = s[ssize - 1 - i];
            s[ssize - 1 - i] = save;
        }
    }
    // slower
    void reverseString2(std::vector<char>& s) {
        std::reverse(s.begin(), s.end());
    }
// 345. Reverse Vowels of a String
    std::string reverseVowels(std::string s) {
        if (s.empty()) {
            return s;
        }
        std::set<char> vowels = {'A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u'};
        size_t begin = 0, end = s.size() - 1;
        for (/**/; begin < end; /**/) {
            if ((vowels.find(s[begin]) != vowels.end())
                && (vowels.find(s[end]) != vowels.end())) {
                char save = s[begin];
                s[begin] = s[end];
                s[end] = save;
                ++ begin;
                -- end;
                continue;
            }
            if (vowels.find(s[begin]) != vowels.end()) {
                -- end;
                continue;
            }
            if (vowels.find(s[end]) != vowels.end()) {
                ++ begin;
                continue;
            }
            -- end;
            ++ begin;
        }
        return s;
    }
// 349. Intersection of Two Arrays
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_map<int, int> inter;
        for (const int el : nums1) {
            inter[el] = -1;
        }
        for (const int el : nums2) {
            if (inter.find(el) != inter.end()) {
                inter[el] = 1;
            }
        }
        std::vector<int> answer;
        for (const auto [key, value] : inter) {
            if (value == 1) {
                answer.push_back(key);
            }
        }
        return answer;
    }
    // faster
    std::vector<int> intersection2(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_set<int> set1(nums1.begin(), nums1.end()), resultSet;

		for(int num : nums2){
			if(set1.find(num) != set1.end()){
				resultSet.insert(num);
			}
		}

		return std::vector<int>(resultSet.begin(), resultSet.end());
    }
// 350. Intersection of Two Arrays II
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_map<int, int> inter;
        for (const int el : nums1) {
            if (inter.find(el) != inter.end()) {
                -- inter[el];
                continue;
            }
            inter[el] = -1;
        }
        std::vector<int> answer;
        for (const int el : nums2) {
            if (inter.find(el) != inter.end()) {
                if (inter[el] <= -1) {
                    answer.push_back(el);
                    ++ inter[el];
                    continue;
                }
            }
        }
        return answer;
    }
    // faster
    std::vector<int> intersect2(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_map<int, int> inter;
        for (const int el : nums1) {
            -- inter[el];
        }
        std::vector<int> answer;
        for (const int el : nums2) {
            if (inter[el] <= -1) {
                answer.push_back(el);
                ++ inter[el];
            }
        }
        return answer;
    }
// 367. Valid Perfect Square
    bool isPerfectSquare(int num) {
        int my_sqrt = mySqrt(num);
        return num == my_sqrt * my_sqrt;
    }
// 374. Guess Number Higher or Lower
    // stub
    int guess (int n) {
        return n % 2;
    }
    // answer
    int guessNumber(int n) {
        int64_t left = 1, right = n, mid = 0;
        for (/**/; left <= right; /**/) {
            mid = (left + right) / 2;
            int r = guess(mid);
            if (r == 0) {
                return mid;
            }
            if (r == 1) {
                left = mid + 1;
                continue;
            }
            if (r == -1) {
                right = mid - 1;
            }
        }
        return mid;
    }
// 383. Ransom Note
    //slow
    bool canConstruct(std::string ransomNote, std::string magazine) {
        std::unordered_map<char, int> magazine_decomposition;
        for (const char c : magazine) {
            ++ magazine_decomposition[c];
        }
        for (const char c : ransomNote) {
            -- magazine_decomposition[c];
            if (magazine_decomposition[c] < 0) {
                return false;
            }
        }
        return true;
    }
    // faster
    bool canConstruct2(std::string ransomNote, std::string magazine) {
        std::vector<int> magazine_decomposition (26, 0);
        for (const char c : magazine) {
            ++ magazine_decomposition[c - 'a'];
        }
        for (const char c : ransomNote) {
            -- magazine_decomposition[c - 'a'];
        }
        for (const int i : magazine_decomposition) {
            if (i < 0) {
                return false;
            }
        }
        return true;
    }
// 387. First Unique Character in a String
    int firstUniqChar(std::string s) {
        std::map<char, int> s_decomp; // letter + id
        std::map<int, int> s_counter; // id + counter
        for (size_t i = 0; i < s.size(); ++ i) {
            if (s_decomp.find(s[i]) == s_decomp.end()) {
                s_decomp[s[i]] = i;
                ++ s_counter[i];
                continue;
            }
            ++ s_counter[s_decomp[s[i]]];
        }
        for (const auto &el : s_counter) {
            if (el.second == 1) {
                return el.first;
            }
        }
        return -1;
    }
// 389. Find the Difference
    char findTheDifference(std::string s, std::string t) {
        if (s.empty()) {
            return t[0];
        }
        std::vector<int> letter_counter (26, 0);
        for (const char c : t) {
            ++ letter_counter[c - 'a'];
        }
        for (const char c : s) {
            -- letter_counter[c - 'a'];
        }
        for (size_t i = 0; i < 26; ++ i) {
            if (letter_counter[i] == 1) {
                return ('a' + i);
            }
        }
        return '!';
    }
// 392. Is Subsequence
    bool isSubsequence(std::string &s, std::string &t) {
        if (s.empty()) {
            return true;
        }
        if (s.size() > t.size()) {
            return false;
        }
        size_t next = 0, t_size = t.size(), s_size = s.size();
        for (size_t i = 0; (i < t_size) && (next < s_size); ++ i) {
            if (s[next] == t[i]) {
                ++ next;
            }
        }
        return next == s_size;
    }
// 404. Sum of Left Leaves
    int MySumOfLeftLeaves (TreeNode* root, bool from_left) {
        if (root == nullptr) {
            return 0;
        }
        if ((root->left == nullptr) && (root->right == nullptr)) {
            if (from_left) {
                return root->val;
            }
            return 0;
        }
        int left_subtree_summ = MySumOfLeftLeaves(root->left, true);
        int right_subtree_summ = MySumOfLeftLeaves(root->right, false);
        return left_subtree_summ + right_subtree_summ;
    }

    int sumOfLeftLeaves (TreeNode* root) {
        return 0 + MySumOfLeftLeaves(root->left, true) + MySumOfLeftLeaves(root->right, false);
    }
// 405. Convert a Number to Hexadecimal
    std::string toHex(int num) {
        if (num == 0) {
            return "0";
        }
        uint32_t val = 0;
        std::string result;
        val += num;
        for (/**/; val > 0; val /= 16) {
            uint8_t mod = val % 16;
            if (mod < 10) {
                result += std::to_string(mod);
                continue;
            }
            result += ('a' + mod - 10);
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
// 338. Counting Bits
    // slow O(n)
    std::vector<int> countBits1(int n) {
        std::vector<int> result(static_cast<int64_t>(n + 1), 0);
        for (unsigned long int i = 0; i <= n; ++ i) {
            for (unsigned long int wrk = 131072; wrk > 0; wrk = wrk >> 1) {
                if ((i & wrk) == wrk) {
                    ++ result[i];
                }
            }
        }
        return result;
    }
    // fast O(n)
    std::vector<int> countBits(int n) {
        std::vector<int> result(n + 1);
        for (int i = 1; i <= n; ++ i) {
            result[i] = result[i / 2] + (i & 1);
        }
        return result;
    }
// 409. Longest Palindrome
    int longestPalindrome(std::string s) {
        if (s.empty()) {
            return 0;
        }
        std::vector<int> letters(255);
        for (const char c : s) {
            ++ letters[c];
        }
        int result = 0;
        bool check_unique_letter = true;
        for (const int el : letters) {
            if (el == 0) {
                continue;
            }
            if (check_unique_letter) {
                if ((el % 2) == 1) {
                    result += el;
                    check_unique_letter = false;
                    continue;
                }
            }
            result += el - (((el % 2) == 1) ? 1 : 0);
        }
        return result;
    }
// 412. Fizz Buzz 
    std::vector<std::string> fizzBuzz(int n) {
        std::vector<std::string> result(n);
        for (int i = 1; i <= n; ++ i) {
            if (((i % 3) == 0) && ((i % 5) == 0)) {
                result[i - 1] = "FizzBuzz";
                continue;
            }
            if ((i % 3) == 0) {
                result[i - 1] = "Fizz";
                continue;
            }
            if ((i % 5) == 0) {
                result[i - 1] = "Buzz";
                continue;
            }
            result[i - 1] = std::to_string(i);
        }
        return result;
    }
// 414. Third Maximum Number
    int thirdMax(std::vector<int>& nums) {
        bool found_1 = true, found_2 = false, found_3 = false;
        int max_1 = nums[0], max_2, max_3;
        if (nums.size() == 1) {
            return max_1;
        }
        for (size_t i = 1; i < nums.size(); ++ i) {
            if (nums[i] > max_1) {
                if (!found_2) {
                    max_2 = max_1;
                    max_1 = nums[i];
                    found_2 = true;
                    continue;
                }
                max_3 = max_2;
                max_2 = max_1;
                max_1 = nums[i];
                found_3 = true;
                continue;
            }
            if (nums[i] != max_1) {
                if (!found_2) {
                    found_2 = true;
                    max_2 = nums[i];
                    continue;
                }
                if (nums[i] > max_2) {
                    max_3 = max_2;
                    max_2 = nums[i];
                    found_3 = true;
                    continue;
                }
                if (nums[i] != max_2) {
                    if (!found_3) {
                        max_3 = nums[i];
                        found_3 = true;
                        continue;
                    }
                    if (nums[i] > max_3) {
                        max_3 = nums[i];
                    }
                }
            }
        }
        if (!found_3) {
            return max_1;
        }
        return max_3;
    }
};

int main() {
    Solution solution;
    std::cout << std::endl;
    auto els = solution.countBits(5);
    for (const auto &el : els) {
        std::cout << el << std::endl;
    }
    return 0;
}
