class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> strs2=strs;
        for(int i=0; i<strs2.size(); i++){
            sort(strs2[i].begin(),strs2[i].end());
        }
        unordered_map<string,int> um;
        int container=1;
        for(int i=0; i<strs2.size(); i++){
            if(um[strs2[i]]==0){
                um[strs2[i]]=container;
                container++;
            }
        }
        vector<vector<string>> ans(container-1);
        for(int i=0; i<strs.size(); i++){
            ans[um[strs2[i]]-1].push_back(strs[i]);
        }
        return ans;
    }
};