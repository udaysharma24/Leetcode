class Solution {
public:
    vector<int> dp=vector<int>(40,-1);
    int tribonacci(int n) {
        if(dp[n]!=-1)
            return dp[n];
        else if(n==0)
            return dp[0]=0;
        else if(n==1)
            return dp[1]=1;
        else if(n==2)
            return dp[2]=1;
        else 
            return dp[n]=tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
    }
};