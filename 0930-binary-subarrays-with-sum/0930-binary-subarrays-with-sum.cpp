class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        vector<int> psum(n);
        psum[0]=nums[0];
        int cnt=0;
        unordered_map<int,int> um;
        um[psum[0]]=1;
        if(psum[0]==goal)
            cnt++;
        for(int i=1; i<n; i++){
            psum[i]=psum[i-1]+nums[i];
            if(psum[i]==goal)
                cnt++;
            if(um.find(psum[i]-goal)!=um.end())
                cnt+=um[psum[i]-goal];
            um[psum[i]]++;
        }
        return cnt;
    }
};