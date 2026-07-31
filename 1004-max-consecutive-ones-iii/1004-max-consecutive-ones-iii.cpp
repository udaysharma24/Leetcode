class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        int window=0;
        int maxwindow=0;
        int temp=0;
        while(l<=r && r<nums.size()){
            if(nums[r]==1)
                r++;
            else if(nums[r]==0 && temp<k){
                temp++;
                r++;
            }
            else if(nums[r]==0 && temp==k){
                while(nums[l]!=0)
                    l++;
                l++;
                if(r<l)
                    r++;
                if(temp>0)
                    temp--;
            }
            window=r-l+1;
            maxwindow=max(window,maxwindow);
        }
        return maxwindow-1;
    }
};