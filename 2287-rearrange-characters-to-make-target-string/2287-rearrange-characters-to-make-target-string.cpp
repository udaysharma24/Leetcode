class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char,int> um1;
        unordered_map<char,int> um2;
        int copies=INT_MAX;
        for(int i=0; i<s.length(); i++){
            um1[s[i]]++;
        }
        unordered_set<char> us;
        for(int i=0; i<target.length(); i++){
            um2[target[i]]++;
            us.insert(target[i]);
        }
        auto it=us.begin();
        while(it!=us.end()){
            copies=min(copies,um1[*it]/um2[*it]);
            it++;
        }
        return copies;
    }
};