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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        vector<pair<int,int>> level_pair;
        while(!q.empty()){
            TreeNode* temp=q.front().first;
            int level=q.front().second;
            if(temp->left!=NULL)
                q.push({temp->left,level+1});
            if(temp->right!=NULL)
                q.push({temp->right,level+1});
            level_pair.push_back({temp->val,level});
            q.pop();
        }
        vector<int> level;
        level.push_back(level_pair[0].first);
        for(int i=1; i<level_pair.size(); i++){
            if(level_pair[i].second==level_pair[i-1].second)    
                level.push_back(level_pair[i].first);
            else{
                ans.push_back(level);
                level.clear();
                level.push_back(level_pair[i].first);
            }
        }
        if(!level.empty()){
            ans.push_back(level);
            level.clear();
        }
        return ans;
    }
};