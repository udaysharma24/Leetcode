class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string ans="";
        while(a>0 && b>0){
            if(a>b){
                if(ans.empty() || ans.back()=='b')
                    ans+="aab";
                else if(ans.empty() || ans.back()=='a')
                    ans+="baa";
                a-=2;
                b--;
            }
            else if(a==b){
                if(ans.empty() || ans.back()=='a')
                    ans+="ba";
                else if(ans.empty() || ans.back()=='b')
                    ans+="ab";
                a--;
                b--;
            }
            else if(a<b){
                if(ans.empty() || ans.back()=='a')
                    ans+="bba";
                else if(ans.empty() || ans.back()=='b')
                    ans+="abb";
                a--;
                b-=2;
            }
        }
        while(b>0){
            ans.push_back('b');
            b--;
        }
        while(a>0){
            ans.push_back('a');
            a--;
        }
        return ans;
    }
};