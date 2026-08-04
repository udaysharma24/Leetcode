class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int window;
        int l=0;
        int r=0;
        int maxwindow=0;
        int temp=0;
        while(l<=r && r<nums.size()){
            if(nums[r]==1){
                r++;
                window=r-l;
                maxwindow=max(window,maxwindow);
            }
            else if(temp==0){
                temp++;
                r++;
                window=r-l;
                maxwindow=max(window,maxwindow);
            }
            else{
                while(temp>0){
                    if(nums[l]==0)
                        temp--;
                    l++;
                    window=r-l;
                }
            }
        }
        return min(maxwindow-1,int(nums.size())-1); 
    }
};