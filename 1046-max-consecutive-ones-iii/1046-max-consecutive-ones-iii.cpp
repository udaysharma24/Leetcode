class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxcnt=0;
        int cnt=0;
        int i=0;
        int j=0;
        int temp=k;
        while(i<nums.size() && j<nums.size())
        {
            if(nums[j]==1)
            {
                cnt++;
                j++;
            }
            else
            {
                if(temp>0)
                {
                    temp--;
                    cnt++;
                    j++;
                }
                else
                {
                    maxcnt=max(cnt, maxcnt);
                    while(nums[i]==1)
                    {
                        i++;
                        cnt--;
                    }
                    if(nums[i]==0)
                    {
                        i++;
                        cnt--;
                        temp++;
                    }
                }
            }
            cout<<i<<" "<<j<<"\n";
        }
        maxcnt=max(cnt, maxcnt);
        return maxcnt;
    }
};