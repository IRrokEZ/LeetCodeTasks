#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>

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
};

int main() {
    Solution solution;
    uint32_t test = 43261596;
    uint32_t result = solution.reverseBits(test);
    std::cout << test << std::endl << result << std::endl;
    return 0;
}
