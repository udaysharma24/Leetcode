class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        bool up=false;
        bool down=false;
        int mn=INT_MAX;
        int mx=INT_MIN;
        int len=1;
        for(int i=0; i<n-1; i++){
            if(nums[i]>nums[i+1] && down==false){
                len++;
                mn=nums[i+1];
                down=true;
                up=false;
            }
            else if(nums[i+1]<mn && down==true)
                mn=nums[i+1];
            else if(nums[i]<nums[i+1] && up==false){
                len++;
                mx=nums[i+1];
                up=true;
                down=false;
            }
            else if(nums[i+1]>mx && up==true)
                mx=nums[i+1];
        }
        return len;
    }
};