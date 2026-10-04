class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n=s.length();
        for(int i=0; i<n; i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                st.push(s[i]);
            else{
                if(st.empty() || abs(st.top()-s[i])>2)
                    return false;
                else if(abs(st.top()-s[i])<=2)
                    st.pop();
            }
        }
        if(st.empty())
            return true;
        return false;
    }
};