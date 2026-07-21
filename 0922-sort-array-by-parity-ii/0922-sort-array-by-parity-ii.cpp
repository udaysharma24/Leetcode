class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> even;
        vector<int> odd;
        for(int i=0; i<n; i++){
            if(nums[i]%2==0)
                even.push_back(nums[i]);
            else
                odd.push_back(nums[i]);
        }
        int index=0;
        while(2*index<n){
            nums[2*index]=even[index];
            nums[2*index+1]=odd[index];
            index++;
        }
        return nums;
    }
};