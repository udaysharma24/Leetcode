class Solution {
public:
    int dp[12][2];

    int dfs(int pos, bool tight, string &num, vector<string> &digits)
    {
        // Successfully formed one valid number
        if(pos == num.size())
            return 1;
        if(dp[pos][tight] != -1)
            return dp[pos][tight];
        int limit = tight ? num[pos]-'0' : 9;
        int ans = 0;
        for(string d : digits)
        {
            int digit = d[0]-'0';
            if(digit > limit)
                continue;
            ans += dfs(pos+1,tight && (digit==limit),num,digits);
        }
        return dp[pos][tight] = ans;
    }

    int atMostNGivenDigitSet(vector<string>& digits, int n)
    {
        string num = to_string(n);
        int len = num.size();
        int m = digits.size();
        int ans = 0;
        // Count numbers having fewer digits
        for(int l=1;l<len;l++)
        {
            ans += pow(m,l);
        }
        memset(dp,-1,sizeof(dp));
        // Count numbers having exactly len digits
        ans += dfs(0,1,num,digits);
        return ans;
    }
};