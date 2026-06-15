class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        vector<vector<bool>> dp= vector<vector<bool>>(n, vector<bool>(n,false));
        for(int i=0; i<n; i++){
            dp[i][i]=true;
        }
        int index=1;
        while(index<n)
        {
            for(int i=0; (i+index)<n; i++){
                int j=i+index;
                if(s[i]==s[j] && j-i==1)    
                    dp[i][j]=true;
                if(s[i]==s[j] && j-i>=2)
                    dp[i][j]=dp[i+1][j-1];
            }
            index++;
        }
        int maxdiff=0;
        int maxi=0;
        int maxj=0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(dp[i][j]==true)
                {
                    maxdiff=max(maxdiff,(j-i));
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(dp[i][j]==true && j-i==maxdiff)
                {
                    maxi=i;
                    maxj=j;
                    break;
                }
            }
        }
        // cout<<maxi<<" "<<maxj<<"\n";
        string ans="";
        for(int i=maxi; i<=maxj; i++){
            ans.push_back(s[i]);
        }
        return ans;
    }
};