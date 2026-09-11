class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        int n=nums.size();
        unordered_map<int,int> um;
        unordered_set<int> us;
        for(int i=0; i<n; i++){
            um[nums[i]]++;
        }
        sort(nums.begin(),nums.end(),[&um](int a, int b){
            if(um[a]==um[b])
                return a<b;
            return um[a]>um[b];
        });
        for(int i=0; i<n; i++){
            us.insert(nums[i]);
            if(us.size()==k)
                break;
        }
        auto it=us.begin();
        while(it!=us.end()){
            ans.push_back(*it);
            it++;
        }
        return ans;
    }
};