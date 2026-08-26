class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int totaldistinct=0;
        set<int> s;
        for(int i=0; i<nums.size(); i++){
            s.insert(nums[i]);
        }
        totaldistinct=s.size();
        int ans=0;
        vector<int> viscount(2001,0);
        for(int i=0; i<nums.size(); i++){
            int l=i;
            int r=i;
            int distinct=0;
            while(r<nums.size()){
                if(viscount[nums[r]]==0){
                    distinct++;
                    viscount[nums[r]]++;
                }
                if(distinct==totaldistinct)
                    ans++;
                r++;
            }
            fill(viscount.begin(),viscount.end(),0);
        }
        return ans;
    }
};