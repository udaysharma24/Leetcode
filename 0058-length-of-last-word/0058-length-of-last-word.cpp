class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt=0;
        int maxcnt=0;
        bool opened=false;
        for(int i=s.length()-1; i>=0; i--){
            if(s[i]==' ' && cnt>0){
                maxcnt=max(cnt,maxcnt);
                return maxcnt;
            }
            else if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
                cnt++;
        }
        maxcnt=max(cnt,maxcnt);
        return maxcnt;
    }
};