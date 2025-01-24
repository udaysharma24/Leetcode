class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int mid=(low+high)/2;
        int sum=0;
        while(low<=high)
        {
            for(int i=0; i<piles.size(); i++)
            {
                if(piles[i]%mid==0)
                    sum+=(piles[i]/mid);
                else if(piles[i]%mid!=0)
                    sum+=((piles[i]/mid)+1);
            }
            if(sum>h)
            {
                low=mid+1;
                if((low+high)%2==0 || (low+high)<2)
                    mid=(low+high)/2;
                else if((low+high)%2==1 && (low+high)>2)
                    mid=((low+high)/2)+1;
                sum=0;
            }
            else if(sum<=h)
            {
                high=mid-1;
                if((low+high)%2==0 || (low+high)<2)
                    mid=(low+high)/2;
                else if((low+high)%2==1 && (low+high)>2)
                    mid=((low+high)/2)+1;
                sum=0;
            }
        }
        if(mid==0)
            mid=1;
        return mid;
    }
};