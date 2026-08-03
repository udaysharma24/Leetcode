class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> um;
        int window=0;
        int maxwindow=0;
        int l=0;
        int r=0;
        while(l<=r && r<s.length()){
            if(um[s[r]]==0){
                um[s[r]]++;
                r++;
                window=r-l;
                maxwindow=max(window,maxwindow);
            }
            else{
                while(um[s[r]]!=0){
                    um[s[l]]--;
                    l++;
                    window=r-l;
                }
            }
        }
        return maxwindow;
    }
};