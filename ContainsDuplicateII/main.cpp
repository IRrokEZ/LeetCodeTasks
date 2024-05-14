#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
// 219. Contains Duplicate II >>
    int abs(int a) {
        if (a > 0) {
            return a;
        }
        return (a * -1);
    }
    bool containsNearbyDuplicate(const std::vector<int>& nums, int k) {
        std::unordered_map<int, int> numbers;
        for(size_t i = 0; i < nums.size(); ++ i){
            if(numbers.find(nums[i]) != numbers.end()){
                if(abs(numbers[nums[i]] - i) <= k ){
                    return true;
                }
            }
            numbers[nums[i]] = i;
        }
        return false;
    }
// 219. Contains Duplicate II <<
// 222. Count Complete Tree Nodes >>
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
    // variant 1 >>
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        if ((root->right == nullptr) && (root->left == nullptr)) {
            return 1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    // variant 1 <<
    // variant 2 >>
    void countFunc (TreeNode* root, int &cntr) {
        if (root == nullptr) {
            return void();
        }
        ++ cntr;
        countFunc(root->left, cntr);
        countFunc(root->right, cntr);
        return void();
    }
    int countNodes2(TreeNode* root) {
        int cntr = 0;
        countFunc(root, cntr);
        return cntr;
    }
    // variant 2 <<
// 222. Count Complete Tree Nodes <<
};

int main()
{
    Solution solution;
    std::cout << solution.containsNearbyDuplicate({1, 2, 3, 1, 2, 3}, 2);
    return 0;
}
