#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::vector<std::string> summaryRanges(const std::vector<int>& nums) {
        std::vector<std::string> result;
        std::string wrk = "";
        int right = nums[0], left = nums[0];
        for (size_t i = 0; i < nums.size(); ++ i) {
            if (wrk.empty()) {
                if (left == right) {
                    left = nums[i];
                    right = nums[i];
                }
                wrk += std::to_string(left);
                std::cout << i << "-" << nums[i] << " empty " << left << " " << right << std::endl;
                continue;
            } 
            if ((nums[i] - right) == 1) {
                ++ right;
                std::cout << i << "-" << nums[i] << " line " << left << " " << right << std::endl;
                continue;
            } 
            if (left == right) {
                result.push_back(wrk);
                wrk = "";
                left = nums[i];
                right = left;
                std::cout << i << "-" << nums[i] << " one_number " << left << " " << right << std::endl;
            } else {
                wrk += "->" + std::to_string(right);
                result.push_back(wrk);
                wrk = "";
                left = nums[i];
                right = left;
                std::cout << i << "-" << nums[i] << " interval " << left << " " << right << std::endl;
            }
        }
        return result;
    }
};


int main () {
    Solution solution;
    std::vector<std::string> result = solution.summaryRanges({0,2,3,4,6,8,9});
    for (const auto &el : result) {
        std::cout << el << std::endl;
    }
    system("pause");
    return 0;
}