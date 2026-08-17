class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        vector<int> ans=nums;
        int r=ans.size()-1;
        while(r>=0){
            ans.push_back(nums[r]);
            r--;
        }
        return ans;
    }
};