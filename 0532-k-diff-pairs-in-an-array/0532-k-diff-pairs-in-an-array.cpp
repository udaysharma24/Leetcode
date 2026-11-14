class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=0;
        int l=0;
        int r=1;
        unordered_map<int,int> x;
        unordered_map<int,int> y;
        while(l<=r && r<n){
            if(l==r || nums[r]-nums[l]<k)
                r++;
            else if(nums[r]-nums[l]==k){
                if(l!=r)
                    ans++;
                x[nums[l]]++;
                y[nums[r]]++;
                while(r<n && x[nums[l]]>0 && y[nums[r]]>0 && nums[r]-nums[l]==k){
                    l++;
                    r++;
                }
            }
            else if(nums[r]-nums[l]>k)
                l++;
        }
        return ans;
    }
};