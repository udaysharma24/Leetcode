class Solution {
public:
    int maximumLength(string s) {
        map<string,int> um;
        for(int i=0; i<s.length(); i++){
            string str="";
            str.push_back(s[i]);
            um[str]++;
            for(int j=i+1; j<s.length(); j++){
                if(s[j]==s[i]){
                    str.push_back(s[j]);
                    um[str]++;
                }
                else
                    break;
            }
        }
        int maxsize=-1;
        for(const auto& [key,value]:um){
            cout<<key<<":"<<value<<"\n";
            if(value>=3)
                maxsize=max(maxsize,int(key.length()));
        }
        return maxsize;
    }
};