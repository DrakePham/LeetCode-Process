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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1){
            TreeNode * result = new TreeNode(val);
            result ->left = root;
            return result;
        }
        int curDepth = 1;
        dfs(root, val, depth, curDepth);
        return root;
    }
    void dfs(TreeNode* curNode, int val, int depth, int curDepth){
        if(!curNode) return;

        if(curDepth == depth - 1){
            TreeNode* left = curNode -> left;
            TreeNode* right = curNode ->right;
            curNode->left = new TreeNode (val);
            curNode->right = new TreeNode(val);
            if (left){
                curNode->left->left = left;
            }
            if (right){
                curNode->right->right = right;
            }
            return;
        }
        dfs(curNode->left, val, depth, curDepth + 1);
        dfs(curNode->right, val, depth, curDepth + 1);
    }
};
