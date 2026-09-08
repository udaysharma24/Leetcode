class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> psum(n,0);
        unordered_map<int,int> um;
        psum[0]=nums[0];
        um[psum[0]%k]=0;
        for(int i=1; i<n; i++){
            psum[i]=psum[i-1]+nums[i];
            if(um.find(psum[i]%k)==um.end())
                um[psum[i]%k]=i;
            if(i-um[psum[i]%k]>1)
                return true;
            if(psum[i]%k==0 && i>=1)
                return true;
        }
        return false;
    }
};