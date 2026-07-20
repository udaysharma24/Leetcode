class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> um;
        int mx=0;
        set<int> maxnums;
        for(int i=0; i<nums.size(); i++){
            um[nums[i]]++;
            mx=max(mx,um[nums[i]]);
        }
        unordered_map<int,int> firstindex;
        unordered_map<int,int> lastindex;
        for(int i=0; i<nums.size(); i++){
            if(um[nums[i]]==mx)
                maxnums.insert(nums[i]);
            if(firstindex.find(nums[i])==firstindex.end())
                firstindex[nums[i]]=i;
        }
        for(int i=nums.size()-1; i>=0; i--){
            if(lastindex.find(nums[i])==lastindex.end())
                lastindex[nums[i]]=i;
        }
        int subarraysize=1e5;
        auto it=maxnums.begin();
        while(it!=maxnums.end()){
            subarraysize=min(lastindex[*it]-firstindex[*it]+1,subarraysize);
            it++;
        }
        return subarraysize;
    }
};