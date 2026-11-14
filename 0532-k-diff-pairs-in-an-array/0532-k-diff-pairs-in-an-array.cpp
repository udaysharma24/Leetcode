class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=0;
        unordered_map<int,int> x;
        unordered_map<int,int> y;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(abs(nums[i]-nums[j])==k && (x[nums[i]]==0 || y[nums[j]]==0)){
                    ans++;
                    x[nums[i]]++;
                    y[nums[j]]++;
                }
            }
        }
        return ans;
    }
};