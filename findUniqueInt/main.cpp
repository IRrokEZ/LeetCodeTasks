#include <vector>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int result = nums[0];
        for (size_t i = 1; i < nums.size(); ++ i) {
            result = result xor nums[i];
        }
        return result;
    }
};

int main()
{
    return 0;
}
