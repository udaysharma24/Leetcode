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
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        queue<TreeNode*> q;
        vector<int> v;
        q.push(root);
        unordered_map<int,int> um;
        while(!q.empty()){
            TreeNode* cur=q.front();
            q.pop();
            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
            v.push_back(cur->val);
        }
        vector<vector<int>> ans;    
        sort(v.begin(),v.end());
        for(int i=0; i<v.size(); i++){
            if(i==0)
                um[v[i]]=-1;
            else
                um[v[i]]=v[i-1];
        }
        for(int i=0; i<queries.size(); i++){
            if(um.find(queries[i])!=um.end())
                ans.push_back({queries[i],queries[i]});
            else{
                auto upperit=lower_bound(v.begin(),v.end(),queries[i]);
                int index=upperit-v.begin();
                int lower,upper;
                if(upperit!=v.end())
                    upper=*upperit;
                if(upperit==v.end())
                    upper=-1;
                if(index>0)
                    lower=v[index-1];
                if(index==0)
                    lower=-1;
                ans.push_back({lower,upper});
            }
            cout<<ans[i][0]<<" "<<ans[i][1]<<"\n";
        }
        return ans;
    }
};