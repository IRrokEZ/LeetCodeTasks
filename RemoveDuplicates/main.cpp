#include <iostream>
#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        std::vector<int> cpy(nums.size());
        cpy[0] = nums[0];
        int k = 1;
        for (size_t i = 1; i < nums.size(); ++ i) {
            if (nums[i - 1] != nums[i]) {
                cpy[k] = nums[i];
                ++ k;
            }
        }
        nums = cpy;
        return k;
    }
};

int main()
{
    Solution solution;
    std::vector <int> test = {0,0,0,1,1,1,2,2,3,3,4};
    std::cout << std::endl << solution.removeDuplicates(test) << std::endl;
    for (const int val : test) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    return 0;
}
