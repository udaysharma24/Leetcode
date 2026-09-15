class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        string newstr="";
        string temp="";
        int opened=0;
        for(int i=0; i<s.length(); i++){
            if(opened==0 && s[i]>=97 && s[i]<=122)
                newstr.push_back(s[i]);
            else if(s[i]==']'){
                opened--;
                while(st.top()!='['){
                    temp.insert(0,1,st.top());
                    st.pop();
                }
                if(st.top()=='[')
                    st.pop();
                string str="";
                while(!st.empty() && st.top()>=48 && st.top()<=57){
                    str.insert(0,1,st.top());
                    st.pop();
                }
                int num=stoi(str);
                string temp1=temp;
                for(int i=1; i<=num-1; i++){
                    temp+=temp1;
                }
                if(st.empty()){
                    newstr += temp;
                }
                else{
                    // Put decoded inner string back into stack
                    for(char c : temp)
                        st.push(c);
                }
                temp = "";
            }
            else{
                if(s[i]=='[')
                    opened++;
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            temp.push_back(st.top());
            st.pop();
        }
        reverse(temp.begin(),temp.end());
        newstr+=temp;
        return newstr;
    }
};