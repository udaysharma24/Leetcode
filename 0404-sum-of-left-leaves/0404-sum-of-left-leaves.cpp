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
    bool isleaf(TreeNode* root){
        if(root->left==NULL && root->right==NULL)
            return true;
        else
            return false;
    }
    int leftleaf(TreeNode* root, bool left){
        if(root==NULL)
            return 0;
        else if(left==true && isleaf(root))
            return root->val;
        else if(!isleaf(root))
            return leftleaf(root->left,true)+leftleaf(root->right,false);
        return 0;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return leftleaf(root,false);
    }
};