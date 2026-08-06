class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        // int seconds=0;
        // int left=0;
        // bool remaining=true;;
        // while(remaining){
        //     remaining=false;
        //     for(int j=0; j<s.length()-1; j++){
        //         if(s[j]=='0' && s[j+1]=='1'){
        //             s[j]='1';
        //             s[j+1]='0';
        //             j++;
        //             remaining=true;
        //         }
        //     }
        //     if(remaining==true)
        //         seconds++;
        // }
        // return seconds;
        int n=s.length();
        vector<vector<int>> dp(2,vector<int>(n,0));
        bool zero=false;
        if(s[0]=='0'){
            dp[0][0]=1;
            dp[1][0]=0;
            zero=true;
        }
        else if(s[0]=='1'){
            dp[0][0]=0;
            dp[1][0]=0;
        }
        for(int i=1; i<n; i++){
            if(s[i]=='0'){
                dp[0][i]=dp[0][i-1]+1;
                dp[1][i]=dp[1][i-1];
                zero=true;
            }
            else{
                dp[0][i]=dp[0][i-1];
                if(zero)
                    dp[1][i]=max(dp[0][i-1],dp[1][i-1]+1);
                else
                    dp[1][i]=dp[1][i-1];
            }
        }
        return dp[1][n-1];
    }
};