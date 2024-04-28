#include <iostream>
#include <vector>

class Solution {
public:
    void Merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        if (n == 0){
            return void();
        }
        if (m == 0) {
            for (int i = 0; i < n; i ++) {
                nums1[i] = nums2[i];
            }
            return void();
        }
        std::vector<int> result(m + n);
        size_t num1_ptr = 0, num2_ptr = 0;
        for (size_t i = 0; i < (m + n); ++ i) {
            if (num1_ptr == m) {
                result[i] = nums2[num2_ptr];
                ++ num2_ptr;
                continue;
            }
            if (num2_ptr == n) {
                result[i] = nums1[num1_ptr];
                ++ num1_ptr;
                continue;
            }
            if (nums1[num1_ptr] < nums2[num2_ptr]){
                result[i] = nums1[num1_ptr];
                ++ num1_ptr;
            } else {
                result[i] = nums2[num2_ptr];
                ++ num2_ptr;
            }
        }
        for (size_t i = 0; i < (m + n); ++ i) {
            nums1[i] = result[i];
        }
        result.clear();
    }
};

int main()
{
    Solution solution;
    std::vector<int> test1 = {1,2,3,0,0,0}, test2 = {2,5,6};
    solution.Merge(test1, 3, test2, 3);
    std::cout << std::endl;
    for(int el : test1) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
    return 0;
}
