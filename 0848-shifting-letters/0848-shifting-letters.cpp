class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int siz=shifts.size();
        vector<int> final(siz);
        final[siz-1]=(shifts[siz-1]%26);
        for(int i=siz-2; i>=0; i--){
            final[i]=(final[i+1]+(shifts[i]%26))%26;
        }
        string ans="";
        for(int i=0; i<final.size(); i++){
            ans.push_back(char(((final[i]+int(s[i]-'a'))%26)+97));
        }
        return ans;
    }
};