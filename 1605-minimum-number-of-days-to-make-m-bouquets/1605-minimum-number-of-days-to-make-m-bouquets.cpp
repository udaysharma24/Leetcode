class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int mid=(low+high)/2;
        int cnt2=0;
        int index=0;
        int ans=-1;
        while(low<=high)
        {
            int cnt=0;
            for(int i=0; i<bloomDay.size(); i++)
            {
                if(mid>=2*bloomDay[i])
                    cnt++;
                if(mid<2*bloomDay[i])
                    cnt+=(mid/bloomDay[i]);
                if((mid/bloomDay[i])==0)
                {
                    cnt2+=(cnt/k);
                    cnt=0;
                }
            }
            cnt2+=(cnt/k);
            if(cnt2<m)
            {
                low=mid+1;
                mid=(low+high)/2;
                cnt2=0;
            }
            else if(cnt2==m)
            {
                ans=mid;
                high=mid-1;
                mid=(low+high)/2;
                cnt2=0;
            }
            else if(cnt2>m)
            {
                ans=mid;
                high=mid-1;
                mid=(low+high)/2;
                cnt2=0;
            }
        }
        return ans;
    }
};