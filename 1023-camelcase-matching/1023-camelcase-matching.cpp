class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans(queries.size(),true);
        for(int i=0; i<queries.size(); i++){
            int m=pattern.length();
            int n=queries[i].length();
            vector<vector<string>> dp(m+1, vector<string>(n+1,""));
            int cnt1=0;
            for(int j=1; j<=m; j++){
                if(pattern[j-1]>=65 && pattern[j-1]<=90)
                    cnt1++;
                for(int k=1; k<=n; k++){
                    if(pattern[j-1]==queries[i][k-1])
                        dp[j][k]=dp[j-1][k-1]+pattern[j-1];
                    else{
                        if(dp[j-1][k].length()>dp[j][k-1].length())
                            dp[j][k]=dp[j-1][k];
                        else
                            dp[j][k]=dp[j][k-1];
                    }
                }
            }
            string lcs=dp[m][n];
            int cnt2=0;
            if(lcs==pattern){
                for(int j=0; j<queries[i].length(); j++){
                    if(queries[i][j]>=65 && queries[i][j]<=90)
                        cnt2++;
                }
                cout<<i<<" "<<cnt1<<" "<<cnt2<<"\n";
                if(cnt1==cnt2)
                    ans[i]=true;
                else
                    ans[i]=false;
            }
            else
                ans[i]=false;
        }
        return ans;
    }
};