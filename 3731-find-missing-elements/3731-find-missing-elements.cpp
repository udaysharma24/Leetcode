class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> missing;
        unordered_map<int,int> um;
        for(int i=0; i<nums.size(); i++){
            um[nums[i]]++;
        }
        int small=nums[0]+1;
        int mx=*max_element(nums.begin(),nums.end());
        while(small<mx){
            if(um[small]==0)
                missing.push_back(small);
            small++;
        }
        return missing;
    }
};