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
class BSTIterator {
public:
    int currentIndex;
    vector<int> list;
    BSTIterator(TreeNode* root) {
        inOrder(root);
        currentIndex = 0;
    }

    void inOrder(TreeNode* node){
        if(!node) return;
        inOrder(node->left);
        list.push_back(node->val);
        inOrder(node->right);
    }
    
    int next() {
        int lengthOfArray = list.size();
        if(currentIndex >= lengthOfArray) return list[lengthOfArray - 1];
        currentIndex += 1;
        return list[currentIndex - 1];
    }
    
    bool hasNext() {
        int lengthOfArray = list.size();
        if(currentIndex < lengthOfArray) return true;
        return false;
    }
};

// 3,7,9,15,20 l = 5
//             |
/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
//  3,7,9,15,20
//  construct the array with the inorder from root
//  current index = 0

//  next:
//  if the currentIndex >= the array length return the final value of the array
//  increase the currentindex 1
//  return array[currentIndex - 1]
 

//  hasNext:
//  currentIndex < the array length