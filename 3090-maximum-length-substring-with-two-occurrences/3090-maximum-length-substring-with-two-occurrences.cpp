class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l=0;
        int r=0;
        unordered_map<char,int> um;
        int window=0;
        int maxwindow=0;
        while(l<=r && r<s.length()){
            if(um[s[r]]<2){
                um[s[r]]++;
                r++;
                window=r-l;
                maxwindow=max(window,maxwindow);
            }
            else{
                while(um[s[r]]==2){
                    um[s[l]]--;
                    l++;
                }
            }
        }
        return maxwindow;
    }
};