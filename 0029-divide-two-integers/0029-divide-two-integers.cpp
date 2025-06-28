class Solution {
public:
    int divide(int dividend, int divisor) {
        long long int dsor=int(divisor);
        long long int dend=int(dividend);
        if(dsor<0)
            dsor=-dsor;
        if(dend<0)
            dend=-dend;
        long long int ans=0;
        while(dend>=dsor)
        {
            long long int cnt=0;
            while(dend>(dsor<<(cnt+1)))
            {
                cnt++;
            }
            ans+=(1<<cnt);
            dend= dend- dsor*(1<<cnt);
        }
        if((dividend<0 && divisor>0) || (dividend>0 && divisor<0))
            ans=-ans;
        if(ans>2147483647)
            ans=2147483647;
        return ans;
    }
};