class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if((long long)m*k>n)
            return -1;
        else if(m*k==n)
            return *max_element(bloomDay.begin(),bloomDay.end());
        else{
            long long int low=1LL;
            long long int high=*max_element(bloomDay.begin(),bloomDay.end());
            int ans;
            while(low<=high){
                int cnt=0;
                int boq=0;
                long long int mid=(low+high)/2;
                for(int i=0; i<n; i++){
                    if(bloomDay[i]<=mid)
                        cnt++;
                    if(cnt==k){
                        cnt=0;
                        boq++;
                    }
                    else if(bloomDay[i]>mid){
                        cnt=0;
                    }
                }
                if(boq>=m){
                    ans=mid;
                    high=mid-1;
                }
                else
                    low=mid+1;
            }
            return ans;
        }
        return -1;
    }
};