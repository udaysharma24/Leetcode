class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int seconds=0;
        int left=0;
        bool remaining=true;;
        while(remaining){
            remaining=false;
            for(int j=0; j<s.length()-1; j++){
                if(s[j]=='0' && s[j+1]=='1'){
                    s[j]='1';
                    s[j+1]='0';
                    j++;
                    remaining=true;
                }
            }
            if(remaining==true)
                seconds++;
        }
        return seconds;
    }
};