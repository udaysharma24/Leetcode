class Solution {
public:
    string reverseWords(string s) {
        vector<string> vs;
        int i=0;
        bool flag=false;
        string a="";
        bool flag2=true;
        while(flag2)
        {
            if(s[i]=='\0')
            {
                if(a[0]!='\0' && a[0]!=' ')
                    vs.push_back(a);
                a="";
                flag2=false;
            }
            else if(s[i]==' ' && flag==false)
            {
                i++;
            }
            else if(s[i]==' ' && flag==true)
            {
                vs.push_back(a);
                a="";
                flag=false;
                i++;
            }
            else if(s[i]!=' ' && flag==false)
            {
                a+=s[i];
                flag=true;
                i++;
            }
            else if(s[i]!=' ' && flag==true)
            {
                a+=s[i];
                i++;
            }
        }
        reverse(vs.begin(), vs.end());
        string ans="";
        for(int i=0; i<vs.size(); i++)
        {
            ans.append(vs[i]);
            if(i<vs.size()-1)
                ans.append(" ");
        }
        return ans;
    }
};