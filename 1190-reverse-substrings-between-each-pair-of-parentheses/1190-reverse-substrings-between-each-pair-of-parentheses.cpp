class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        int n=s.length();
        string ans="";
        for(int i=0; i<n; i++){
            if(s[i]==')'){
                string str="";
                while(!st.empty() && st.top()!='('){
                    char ch=st.top();
                    str.push_back(ch);
                    st.pop();
                }
                if(st.top()=='(')
                    st.pop();
                if(st.empty()){
                    for(int j=0; j<str.length(); j++){
                        ans.push_back(str[j]);
                    }
                }
                else{
                    for(int j=0; j<str.length(); j++){
                        st.push(str[j]);
                    }
                }
            }
            else if(st.empty() && s[i]!='(')
                ans.push_back(s[i]);
            else
                st.push(s[i]);
        }
        return ans;
    }
};