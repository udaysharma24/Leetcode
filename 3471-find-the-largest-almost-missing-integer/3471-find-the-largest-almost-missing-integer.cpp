class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==n)
            return *max_element(nums.begin(),nums.end());
        else if(k==1){
            unordered_map<int,int> um;
            for(int i=0; i<n; i++){
                um[nums[i]]++;
            }
            int ans=-1;
            for(int i=0; i<n; i++){
                if(um[nums[i]]==1)
                    ans=max(ans,nums[i]);
            }
            return ans;
        }
        else{
            int left=nums[0];
            int right=nums[n-1];
            unordered_map<int,int> um;
            for(int i=0; i<n; i++){
                um[nums[i]]++;
            }
            int ans=-1;
            if(max(left,right)==left && um[left]==1)
                ans=left;
            else if(max(left,right)==right && um[right]==1)
                ans=right;
            else if(um[left]==1)
                ans=left;
            else if(um[right]==1)
                ans=right;
            return ans;
        }
    }
};