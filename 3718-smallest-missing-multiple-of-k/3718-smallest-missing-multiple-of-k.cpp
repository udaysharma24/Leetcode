class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,bool> um;
        for(int i=0; i<nums.size(); i++){
            um[nums[i]]=true;
        }
        int i=1;
        while(um[k*i]){
            i++;
        }
        return k*i;
    }
};