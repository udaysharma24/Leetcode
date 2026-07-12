class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int cnt=0;
        unordered_map<int,int> um;
        vector<int> ans(arr.size());
        vector<int> temp=arr;
        sort(temp.begin(),temp.end());
        for(int i=0; i<temp.size(); i++){
            if(um[temp[i]]==0)
                cnt++;
            um[temp[i]]=cnt;
        }
        for(int i=0; i<arr.size(); i++){
            ans[i]=um[arr[i]];
        }
        return ans;
    }
};