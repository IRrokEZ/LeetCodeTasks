#include <iostream>
#include <vector>
// #include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        for (size_t i = 0; i < nums.size() - 1; ++ i) {
            for (size_t j = i + 1; j < nums.size(); ++ j) {
                if ((nums[i] + nums[j]) == target) {
                    vector <int> result(2);
                    result[0] = i;
                    result[1] = j;
                    return result;
                }
            }
        }
        return {};
        /*
        unordered_map <int, int> visited;
        for (int i = 0; i < nums.size(); i ++) {
            int complement = target - nums[i];
            if (visited.count(complement)) {
                return {visited[complement], i};
            }
            visited[nums[i]] = i;
        }
        return {};
        */
    }
};

int main()
{

    return 0;
}
