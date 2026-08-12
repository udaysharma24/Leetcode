class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> prefixsum(n);
        prefixsum[0]=nums[0];
        int cnt=0;
        int rem=prefixsum[0]%k;
        if(rem<0)
            rem+=k;
        unordered_map<int,int> um; 
        um[0]++;
        if(um[rem]>0)
            cnt+=um[rem];
        um[rem]++;
        for(int i=1; i<n; i++){
            prefixsum[i]=prefixsum[i-1]+nums[i];
            int rem=prefixsum[i]%k;
            if(rem<0)
                rem+=k;
            if(um[rem]>0)
                cnt+=um[rem];
            um[rem]++;
        }
        return cnt;
    }
};