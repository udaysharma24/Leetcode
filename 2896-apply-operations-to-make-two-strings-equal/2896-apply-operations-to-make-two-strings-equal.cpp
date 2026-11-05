class Solution {
public:
    int minOperations(string s1, string s2, int x) {
        int n=s1.size();
        vector<int> index;
        for(int i=0; i<n; i++){
            if(s1[i]!=s2[i])
                index.push_back(i);
        }
        int siz=index.size();
        if(siz%2==1)
            return -1;
        if(siz==0)
            return 0;
        vector<int> dp(siz+1);
        dp[0]=0; // value=0 for 0 mismatches
        dp[1]=x; // value=x for 1 mismatch 
        for(int i=2; i<=siz; i++){
            dp[i]=min(dp[i-1]+x,dp[i-2]+2*(index[i-1]-index[i-2]));
        }
        return dp[siz]/2;
    }
};