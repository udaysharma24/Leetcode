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
    void maxbtree(TreeNode* root, vector<int>& nums){
        if(nums.empty())
            return ;
        int maxval=*max_element(nums.begin(),nums.end());
        root->val=maxval;
        int maxindex=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==maxval)
                maxindex=i;
        }
        root->val=maxval;
        vector<int> nums1(nums.begin(),nums.begin()+maxindex);
        vector<int> nums2(nums.begin()+maxindex+1,nums.end());
        if(!nums1.empty()){
            TreeNode* newnode1=new TreeNode();
            root->left=newnode1;
        }
        if(!nums2.empty()){
            TreeNode* newnode2=new TreeNode();
            root->right=newnode2;
        }
        maxbtree(root->left,nums1);
        maxbtree(root->right,nums2);
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root=new TreeNode();
        maxbtree(root,nums);
        return root;
    }
};