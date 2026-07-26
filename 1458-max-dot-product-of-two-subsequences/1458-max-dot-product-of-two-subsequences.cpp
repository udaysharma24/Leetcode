class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                dp[i][j]=max({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]+(nums1[i-1]*nums2[j-1])});
            }
        }
        bool flag1=true,flag2=true;
        for(int i=0; i<m; i++){
            if(nums1[i]>0){
                flag1=false;
                break;
            }
        }
        for(int i=0; i<n; i++){
            if(nums2[i]>0){
                flag2=false;
                break;
            }
        }
        int ans;
        if((flag1==false && flag2==false) || (flag1==true && flag2==true))
            ans=dp[m][n];
        else if(flag1==true){
            int mx1=*max_element(nums1.begin(),nums1.end());
            int mn2=*min_element(nums2.begin(),nums2.end());
            ans=mx1*mn2;
        }
        else if(flag2==true){
            int mn1=*min_element(nums1.begin(),nums1.end());
            int mx2=*max_element(nums2.begin(),nums2.end());
            ans=mn1*mx2;
        }
        return ans;
    }
};