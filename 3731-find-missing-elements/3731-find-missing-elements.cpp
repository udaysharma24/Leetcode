class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> v;
        unordered_map<int,int> um;
        for(int i=0; i<nums.size(); i++){
            um[nums[i]]++;
        }
        int mn=*min_element(nums.begin(),nums.end());
        int mx=*max_element(nums.begin(),nums.end());
        for(int i=mn; i<=mx; i++){
            if(um[i]==0)
                v.push_back(i);
        }
        return v;
    }
};