class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_map<int,int> um;
        for(int i=0; i<nums.size(); i++){
            um[nums[i]]++;
        }
        int sum=nums[0];
        if(nums.size()==1)
            return nums[0]+1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]==nums[i-1]+1)
                sum+=nums[i];
            else{
                while(um[sum]!=0)
                    sum++;
                break;
            }
        }
        return sum;
    }
};