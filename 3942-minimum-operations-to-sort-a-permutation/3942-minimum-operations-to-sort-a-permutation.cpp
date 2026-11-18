class Solution {
public:
    int solve(vector<int>& nums){
        int n=nums.size();
        if(n==1)
            return 0;
        vector<int> v(nums);
        for(int i=0; i<nums.size(); i++){
            v.push_back(nums[i]);
        }
        int count=1;
        for(int i=1; i<v.size(); i++){
            if(v[i]<v[i-1])
                count=1;
            else{
                count++;
                if(count==n)
                    return i+1-n;
            }
        }
        count=1;
        for(int i=1; i<v.size(); i++){
            if(v[i]>v[i-1])
                count=1;
            else{
                count++;
                if(count==n)
                    return i+2-n;
            }
        }
        return 1e9;
    }
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int ans=solve(nums);
        reverse(nums.begin(),nums.end());
        ans=min(ans,solve(nums)+1);
        if(ans==1e9)
            return -1;
        return ans;
    }
};