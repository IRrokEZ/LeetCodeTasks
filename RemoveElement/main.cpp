#include <iostream>
#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
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
};

int main()
{
    Solution solution;
    std::vector <int> test = {0,0,0,1,1,1,2,2,3,3,4};
    std::cout << std::endl << solution.removeElement(test, 2) << std::endl;
    for (const int val : test) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    return 0;
}
