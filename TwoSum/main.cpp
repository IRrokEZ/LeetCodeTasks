#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target) {
        std::unordered_map <int, int> visited;
        for (int i = 0; i < nums.size(); i ++) {
            int complement = target - nums[i];
            if (visited.count(complement)) {
                return {visited[complement], i};
            }
            visited[nums[i]] = i;
        }
        return {-1, -1};
    }
};

int main()
{
    Solution solution;
    std::vector <int> result, nums = {2,7,11,15};
    result = solution.twoSum(nums, 9);
    std::cout << std::endl << result[0] << " " << result [1] << std::endl;
    return 0;
}
