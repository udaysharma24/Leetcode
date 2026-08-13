class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return 0;
        vector<int> prefixsum(n+1);
        prefixsum[0]=-1;
        int window=0;
        int maxwindow=0;
        unordered_map<int,int> um;
        um[prefixsum[0]]=0;
        for(int i=0; i<n; i++){
            if(nums[i]==1)
                prefixsum[i+1]=prefixsum[i]+1;
            if(nums[i]==0)
                prefixsum[i+1]=prefixsum[i]-1;
            if(um.find(prefixsum[i+1])==um.end())
                um[prefixsum[i+1]]=i+1;
            else{
                window=i+1-um[prefixsum[i+1]];
                maxwindow=max(maxwindow,window);
            }
        }
        return maxwindow;
    }
};