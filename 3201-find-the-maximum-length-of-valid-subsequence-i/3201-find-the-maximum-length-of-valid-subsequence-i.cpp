class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<int,int> um;
        int oddcnt=0;
        int evencnt=0;
        int alternating=1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%2==1)
                oddcnt++;
            else if(nums[i]%2==0)
                evencnt++;
        }
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]%2!=nums[i+1]%2)
                alternating++;
        }
        return max({evencnt,oddcnt,alternating});
    }
};