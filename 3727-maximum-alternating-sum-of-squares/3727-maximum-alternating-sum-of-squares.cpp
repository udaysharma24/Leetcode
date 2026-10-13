class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        for(int i=0; i<n; i++){
            nums[i]=abs(nums[i]);
        }
        sort(nums.begin(),nums.end());
        vector<int> small;
        vector<int> large;
        int index=-1;
        for(int i=0; i<n/2; i++){
            small.push_back(nums[i]);
            index=i+n/2;
            large.push_back(nums[index]);
        }
        index++;
        if(index<n)
            large.push_back(nums[index]);
        long long int ans=0LL;
        for(int i=0; i<large.size(); i++){
            ans+=(long long)large[i]*(long long)large[i];
        }
        for(int i=0; i<small.size(); i++){
            ans-=(long long)small[i]*(long long)small[i];
        }
        return ans;
    }
};