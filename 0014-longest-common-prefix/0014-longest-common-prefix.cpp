class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int n= strs.size()-1;
        string a="";
        for(int i=0; i<strs[0].length() && i<strs[n].length(); i++)
        {
            if(strs[0][i]==strs[n][i])
            {
                a+=(strs[0][i]);
            }
            else
            {
                return a;
            }
        }
        return a;
    }
};