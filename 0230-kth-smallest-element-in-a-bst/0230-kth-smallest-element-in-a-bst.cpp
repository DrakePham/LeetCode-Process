/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int result = -1;

        helper(root, k, result);
        return result;
    }

    void helper(TreeNode* node, int& k, int& result){
        if(!node) return;
        helper(node->left, k, result);

        if(--k == 0){
            result = node->val;
            return;
        }
        helper(node->right, k, result);

    }
    
};