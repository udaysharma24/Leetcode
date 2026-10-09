class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> temp(score);
        sort(temp.begin(),temp.end(),greater<int>());
        unordered_map<int,string> um;
        um[temp[0]]="Gold Medal";
        if(temp.size()>=2)
            um[temp[1]]="Silver Medal";
        if(temp.size()>=3)
            um[temp[2]]="Bronze Medal";
        if(temp.size()>=4){
            for(int i=3; i<temp.size(); i++){
                um[temp[i]]=to_string(i+1);
            }
        }
        vector<string> ans(score.size());
        for(int i=0; i<score.size(); i++){
            ans[i]=um[score[i]];
        }
        return ans;
    }
};