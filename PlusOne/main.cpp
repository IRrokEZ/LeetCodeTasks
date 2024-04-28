#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
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
};

int main()
{
    Solution solution;
    std::vector <int> test = {1,3,4,5,6,8,9};
    std::vector <int> res = solution.plusOne(test);
    std::cout << std::endl;
    for (const auto dig :  res) {
        std::cout << dig;
    }
    std::cout << std::endl;
    return 0;
}
