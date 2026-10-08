class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.length();
        int khata=0;
        string ans="";
        for(int i=0; i<n; i++){
            if(s[i]=='(' && khata==0)
                khata++;
            else if(s[i]=='(' && khata>0){
                ans.push_back(s[i]);
                khata++;
            }
            else if(s[i]==')' && khata>1){
                ans.push_back(s[i]);
                khata--;
            }
            else if(s[i]==')' && khata>0)
                khata--;
        }
        return ans;
    }
};