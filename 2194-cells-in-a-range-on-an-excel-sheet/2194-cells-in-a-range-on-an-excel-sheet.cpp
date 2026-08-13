class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> ans;
        char startchar=s[0];
        char endchar=s[3];
        int startint=int(s[1]-48);
        int endint=int(s[4]-48);
        for(char i=startchar; i<=endchar; i++){
            for(int j=startint; j<=endint; j++){
                string s="";
                s.push_back(i);
                s.push_back(char(j+48));
                ans.push_back(s);
            }
        }
        return ans;
    }
};