class Solution {
public:
    string lastNonEmptyString(string s) {
        vector<int> v(26,0);
        int n=s.length();
        for(int i=0; i<n; i++){
            v[s[i]-97]++;
        }
        int mx=0;
        for(int i=0; i<26; i++){
            if(v[i]>mx)
                mx=v[i];
        }
        string ans="";
        unordered_map<char,int> um;
        for(int i=0; i<n; i++){
            um[s[i]]++;
            if(um[s[i]]==mx)
                ans.push_back(s[i]);
        }
        return ans;
    }
};