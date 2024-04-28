#include <iostream>
#include <vector>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        int sz = nums.size();
        int beg = 0, mid = sz / 2, last = sz - 1;
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
        if (target > nums[last]) {
            return (last + 1);
        }
        return -1;
    }
};

int main()
{
    Solution solution;
    std::vector <int> test = {1,3,4,5,6,8,10};
    std::cout << std::endl << solution.searchInsert(test, 5) << std::endl;
    return 0;
}
