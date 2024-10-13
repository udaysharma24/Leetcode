class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> m;
        int n=nums.size();
        int ans;
        for(int i=0; i<n; i++)
        {
            m[nums[i]]++;
            if(m[nums[i]]>n/2)
            {
                ans=nums[i];
                break;
            }
        }
        return ans;
    }
};