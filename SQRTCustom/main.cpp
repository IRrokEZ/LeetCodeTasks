#include <iostream>

class Solution {
public:
    int mySqrt(int x) {
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
};

int main()
{
    Solution solution;
    int test = 1024;
    std::cout << std::endl << solution.mySqrt(test) << std::endl;
    return 0;
}
