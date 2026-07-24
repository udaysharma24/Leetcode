class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m=str1.length();
        int n=str2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    if(dp[i-1][j]>dp[i][j-1])
                        dp[i][j]=dp[i-1][j];
                    else
                        dp[i][j]=dp[i][j-1];
                }
            }
        }
        string ans="";
        int i = m, j = n;
        while(i > 0 && j > 0){
            if(str1[i-1] == str2[j-1]){
                ans += str1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }

        reverse(ans.begin(), ans.end());
        if(ans.length()==str1.length() && ans.length()==str2.length())
            return ans;
        string finalstring="";
        int k=0;
        j=0;
        for(int i=0; i<ans.length(); i++){
            while(str1[k]!=ans[i]){
                finalstring+=str1[k++];
            }
            while(str2[j]!=ans[i]){
                finalstring+=str2[j++];
            }
            finalstring+=ans[i];
            k++;
            j++;
        }
        return finalstring+str1.substr(k)+str2.substr(j);
    }
};