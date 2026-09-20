class Solution {
public:
    int reverseDegree(string s) {
        int n=s.length();
        int sum=0;
        unordered_map<char,int> um;
        for(int i=0; i<26; i++){
            um[char(97+i)]=26-i;
        }
        for(int i=0; i<n; i++){
            sum+=(um[s[i]]*(i+1));
        }
        return sum;
    }
};