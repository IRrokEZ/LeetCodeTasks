#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool checkSymmetric(TreeNode *lft, TreeNode *rght) {
        if ((lft == nullptr) && (rght == nullptr)) {
            return true;
        }
        if ((lft == nullptr) || (rght == nullptr)) {
            return false;
        }
        bool result = lft->val == rght->val
                && checkSymmetric(lft->left, rght->right)
                && checkSymmetric(lft->right, rght->left);
        return result;
    }
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        if ((root->left == nullptr) && (root->right == nullptr)) {
            return true;
        }
        return checkSymmetric(root->left, root->right);
    }
};

int main()
{
    return 0;
}
