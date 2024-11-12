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
    
    int closestValue(TreeNode* root, double target) {
       int result = INT_MAX;
       helper(root, target, result);
       return result;
    }
    void helper(TreeNode* root, double target, int& result){
        if(!root) return;
        if(abs(result - target) > abs(target - root->val)) result = root->val;
        else if(abs(result - target) == abs(target - root->val)) result = min(result, root->val);
        cout<<root->val<<endl;
        helper(root->left, target, result);
        helper(root->right, target, result);

    }
};