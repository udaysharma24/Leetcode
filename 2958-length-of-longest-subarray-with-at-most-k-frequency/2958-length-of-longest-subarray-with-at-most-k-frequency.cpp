class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        unordered_map<int,int> um;
        int window=0;
        int maxwindow=0;
        while(l<=r && r<nums.size()){
            if(um[nums[r]]<k){
                um[nums[r]]++;
                r++;
                window=r-l;
                maxwindow=max(window,maxwindow);
            }
            else{
                while(um[nums[r]]>=k){
                    um[nums[l]]--;
                    l++;
                }
                window=r-l;
            }
        }
        return maxwindow;
    }
};