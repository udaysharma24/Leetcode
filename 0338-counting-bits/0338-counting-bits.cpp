class Solution {
public:
    vector<int> dp=vector<int>(100001,-1);
    int bits(int num){
        if(dp[num]!=-1)
            return dp[num];
        if(num==0)
            return dp[num]=0;
        if(num==1)
            return dp[num]=1;
        int temp=num;
        if(temp%2==1)
            return dp[num]=1+bits(temp/2);
        return dp[num]=bits(temp/2);
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0; i<=n; i++){
            if(dp[i]!=-1)
                ans.push_back(dp[i]);
            else
                ans.push_back(bits(i));
        }
        return ans;
    }
};