class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> um;
        for(int i=0; i<n; i++){
            um[nums[i]]++;
        }
        int maxlen=0;
        for(int i=0; i<n; i++){
            if(um[nums[i]-1]!=0)
                maxlen=max(maxlen,um[nums[i]]+um[nums[i]-1]);
        }
        return maxlen;
    }
};