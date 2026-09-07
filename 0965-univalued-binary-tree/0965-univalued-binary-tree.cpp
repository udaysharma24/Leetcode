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
    bool hassameval(TreeNode* root, int val){
        if(root==NULL)
            return true;
        if(root->val==val)
            return hassameval(root->left,root->val) && hassameval(root->right,root->val);
        else
            return false;
    }
    bool isUnivalTree(TreeNode* root) {
        return hassameval(root->left,root->val) && hassameval(root->right,root->val);
    }
};