class Solution {
public:
    long long minimumMaxValue(int n, int index, int value) {
        if(value==1)
            return (long long)(-1);
        if(n==1)
            return value;
        long long int spf=value;
        long long int ans=(long long)(-1);
        long long init_val=(long long)(-1);
        if(value%2==0){
            spf=2LL;
            ans=((n-1-index)*2)+(long long)value;
            if(value-2LL*index<=0)
                return -1;
        }
        if(value%2==1){
            for(int i=3; i<=sqrt(value); i++){
                if(value%i==0LL){
                    spf=i;
                    break;
                }
            }
            if(index<n-1)
                ans=(long long)value+spf+((n-1-(index+1))*2);
            if(index==n-1)
                ans=(long long)value;
            if(index>=1)
                init_val=(long long)value-spf-((index-1)*2);
            if(index==0)
                init_val=(long long)value;
            if(init_val<=0)
                ans=(long long)(-1);
        }
        return ans;
    }
};