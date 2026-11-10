class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n<=2)
            return n;
        int l=0;
        int r=0;
        while(r<n){
            int cnt=1;
            while(r<n-1 && nums[r]==nums[r+1]){
                cnt++;
                r++;
            }
            for(int i=0; i<min(2,cnt); i++){
                nums[l]=nums[r];
                l++;
            }
            r++;
        }
        return l;
    }
};