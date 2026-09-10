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
    int preorder(TreeNode* root){
        if(root==NULL)  
            return 0;
        return 1+preorder(root->left)+preorder(root->right);
    }
    int sum(TreeNode* root){
        if(root==NULL)
            return 0;
        return root->val+sum(root->left)+sum(root->right);
    }
    int average(TreeNode* root){
        int nodecount=preorder(root);
        if(root==NULL)
            return 0;
        else if(root->val==sum(root)/nodecount)
            return 1+average(root->left)+average(root->right);
        else
            return average(root->left)+average(root->right);
    }
    int averageOfSubtree(TreeNode* root) {
        return average(root);
    }
};