class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        int mid=(low+high)/2;
        int ans=mid;
        int cnt=1;
        int load=0;
        while(low<=high)
        {
            for(int i=0; i<weights.size(); i++)
            {
                if(load+weights[i]<=mid)
                    load+=weights[i];
                else
                {
                    cnt++;
                    load=weights[i];
                }
            }
            if(cnt>days)
            {
                low=mid+1;
                mid=(low+high)/2;
                cnt=1;
                load=0;
            }
            else if(cnt==days)
            {
                ans=mid;
                high=mid-1;
                mid=(low+high)/2;
                cnt = 1;
                load = 0;
            }
            else if(cnt<days)
            {
                ans=mid;
                high=mid-1;
                mid=(low+high)/2;
                cnt=1;
                load=0;
            }
        }
        return ans;
    }
};