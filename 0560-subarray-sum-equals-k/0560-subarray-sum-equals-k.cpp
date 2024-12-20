class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int psum=0;
        int cnt=0;
        map<int,int> m;
        m[0]++;
        for(int i=0; i<nums.size(); i++)
        {
            psum+=nums[i];
            if(m.find(psum-k)!=m.end())
                cnt+=m[psum-k];
            m[psum]++;
        }
        return cnt;
    }
};