class Solution {
public:
    string removeOuterParentheses(string s) {
        int mark=0;
        string a;
        for(int i=0; i<s.length(); i++)
        {
            if(mark<0)
            {
                if(s[i]=='(')
                {
                    mark--;
                    if(mark<0)
                        a.push_back(s[i]);
                }
                else
                {
                    mark++;
                    if(mark<0)
                        a.push_back(s[i]);
                }
            }
            else if(s[i]=='(')
                mark--;
            else
                mark++;
        }
        return a;
    }
};