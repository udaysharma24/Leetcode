class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int ans=1;
        set<int> s;
        for(int i=0; i<nums.size(); i++)
        {
            s.insert(nums[i]);
        }
        int cnt=1;
        auto it1=s.begin();
        auto it2=(++s.begin());
        while(it2!=s.end())
        {
            if((*it1)+1==(*it2))
                cnt++;
            else
            {
                ans=max(cnt,ans);
                cnt=1;
            }
            it1++;
            it2++;
        }
        ans=max(cnt,ans);
        return ans;
    }
};