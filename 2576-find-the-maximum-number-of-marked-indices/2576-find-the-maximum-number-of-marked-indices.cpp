class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int l=0;
        int r=(n+1)/2;
        int marked=0;
        while(l<r && r<n){
            if(nums[r]>=2*nums[l]){
                l++;
                r++;
                marked+=2;
            }
            else
                r++;
        }
        return marked;
    }
};