#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
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
};

int main()
{
    Solution solution;
    std::cout << std::endl << solution.isPalindrome(234567899) << std::endl;
    return 0;
}
