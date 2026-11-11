class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=0;
        int cnt=0;
        unordered_map<int,int> um;
        while(r<n){
            int cnt=1;
            while(r<n-1 && nums[r]==nums[r+1]){
                cnt++;
                r++;
            }
            for(int i=0; i<min(1,cnt); i++){
                nums[l]=nums[r];
                l++;
            }
            r++;
        }
        return l;
    }
};