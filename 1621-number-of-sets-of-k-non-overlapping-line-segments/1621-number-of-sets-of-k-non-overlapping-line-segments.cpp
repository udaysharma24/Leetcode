class Solution {
public:
    int MOD=1e9+7;
    int dp[1003][1003];
    int prefixdp[1003][1003];
    int mod(int a){
        return a%MOD;
    }
    int add(int a, int b){
        return mod(mod(a)+mod(b));
    }
    int mul(int a, int b){
        return mod(mod(a)*mod(b));
    }
    int prefixok(int n, int k){
        if(n==1)
            return 0;
        if(prefixdp[n][k]!=-1)
            return prefixdp[n][k];
        return prefixdp[n][k]=add(prefixok(n-1,k),ok(n,k));
    }
    int ok(int n, int k){
        if(k==1)
            return dp[n][k]=(n*(n-1))/2;
        else if(k==n-1)
            return dp[n][k]=1;
        else if(n==1 || k>n-1)  
            return dp[n][k]=0;
        int total=0;
        total=add(total,ok(n-1,k));
        total=add(total,prefixok(n-1,k-1));
        return dp[n][k]=total;
    }
    int numberOfSets(int n, int k) {
        memset(dp,-1,sizeof(dp));
        memset(prefixdp,-1,sizeof(prefixdp));
        return ok(n,k);
    }
};