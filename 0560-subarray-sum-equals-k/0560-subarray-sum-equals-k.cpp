class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> psum(n,0);
        unordered_map<int,int> um;
        int ans=0;
        psum[0]=nums[0];
        um[psum[0]]=1;
        if(psum[0]==k)
            ans++;
        for(int i=1; i<n; i++){
            psum[i]=psum[i-1]+nums[i];
            if(psum[i]==k)
                ans++;
            if(um.find(psum[i]-k)!=um.end())
                ans+=um[psum[i]-k];
            um[psum[i]]++;
        }
        return ans;
    }
};