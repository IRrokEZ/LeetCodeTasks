#include <iostream>
#include <string>

class Solution {
public:
    int CharToInt(char sym) {
        return (sym == '1')? 1 : 0;
    }
    char IntToChar(int num) {
        return (num == 1)? '1' : '0';
    }
    std::string addBinary(std::string a, std::string b) {
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
                r = CharToInt(min_num[min_sz - i]) +
                    CharToInt(max_num[max_sz - i]) +
                    div;
            } else {
                r = CharToInt(max_num[max_sz - i]) +
                    div;
            }
            div = r / 2;
            mod = r % 2;
            res[max_sz + 1 - i] = IntToChar(mod);
        }
        if (div == 1) {
            res[0] = IntToChar(div);
        } else {
            res.erase(res.begin());
        }
        return res;
    }
};

int main()
{
    Solution solution;
    std::string test1 = "101010111", test2 = "10011";
    std::cout << std::endl << solution.addBinary(test1, test2) << std::endl;
    return 0;
}
