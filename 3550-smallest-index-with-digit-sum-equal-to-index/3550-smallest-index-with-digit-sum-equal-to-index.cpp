class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        vector<int> digits(nums.size());
        for(int i=0; i<nums.size(); i++){
            string s=to_string(nums[i]);
            int sum=0;
            for(int i=0; i<s.length(); i++){
                sum+=(s[i]-48);
            }
            if(sum==i)
                return i;
        }
        return -1;
    }
};