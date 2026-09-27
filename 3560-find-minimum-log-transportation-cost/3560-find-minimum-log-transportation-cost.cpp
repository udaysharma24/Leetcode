class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        long long int mincost=0LL;
        if(n>k){
            for(long long int i=1; i<=n/2; i++){
                if(i<=k && n-i<=k){
                    mincost=(long long)(i*(n-i));
                    break;
                }
            }
        }
        if(m>k){
            for(long long int i=1; i<=m/2; i++){
                if(i<=k && m-i<=k){
                    mincost=(long long)(i*(m-i));
                    break;
                }
            }
        }
        return mincost;
    }
};