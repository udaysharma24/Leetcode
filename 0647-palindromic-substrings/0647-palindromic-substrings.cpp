class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        int cnt=0;
        for(int i=0; i<n; i++){
            int l=i;
            int r=i;
            while(l>=0 && r<n && s[l]==s[r]){
                cnt++;
                l--;
                r++;
            }
        }
        for(int i=0; i<n; i++){
            int l=i;
            int r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                cnt++;
                l--;
                r++;
            }
        }
        return cnt;
    }
};