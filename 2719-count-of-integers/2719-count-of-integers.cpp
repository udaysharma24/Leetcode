class Solution {
public:
    const int MOD = 1e9 + 7;
    int dp[25][2][401];

    int dfs(int pos,
            bool tight,
            int sum,
            string &s,
            int minSum,
            int maxSum)
    {
        if(sum > maxSum)
            return 0;
        if(pos==s.size())
        {
            return (sum>=minSum && sum<=maxSum);
        }

        if(dp[pos][tight][sum]!=-1)
            return dp[pos][tight][sum];

        int limit = tight ? s[pos]-'0' : 9;

        int ans=0;

        for(int digit=0;digit<=limit;digit++)
        {
            ans = (ans+dfs(pos+1,tight && (digit==limit),sum+digit,s,minSum,maxSum))%MOD;
        }

        return dp[pos][tight][sum]=ans;
    }
    int solve(string s,int minSum,int maxSum)
    {
        memset(dp,-1,sizeof(dp));

        return dfs(0,1,0,s,minSum,maxSum);
    }
    string subtractOne(string s) {
        int i = s.size() - 1;

        while (i >= 0 && s[i] == '0') {
            s[i] = '9';
            i--;
        }

        if (i >= 0)
            s[i]--;

        // Remove leading zeros
        int pos = 0;
        while (pos + 1 < s.size() && s[pos] == '0')
            pos++;

        return s.substr(pos);
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        string left = subtractOne(num1);
        return (solve(num2, min_sum, max_sum) - solve(left, min_sum, max_sum)+MOD)%MOD;
    }
};