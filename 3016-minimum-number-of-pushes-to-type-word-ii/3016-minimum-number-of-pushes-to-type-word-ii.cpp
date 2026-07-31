class Solution {
public:
    int minimumPushes(string word) {
        if(word.length()<=8)
            return word.length();
        else{
            unordered_map<char,int> count;
            for(int i=0; i<word.length(); i++){
                count[word[i]]++;
            }
            sort(word.begin(),word.end(),[&count](char a, char b){
                if(count[a]!=count[b])
                    return count[a]>count[b];
                return a<b;
            });
            unordered_map<char,int> um;
            int len=0;
            int rep=1;
            int final_len=0;
            for(int i=0; i<word.length(); i++){
                if(um[word[i]]==0 && len<8){
                    um[word[i]]=rep;
                    len++;
                }
                else if(um[word[i]]==0){
                    rep++;
                    len=1;
                    um[word[i]]=rep;
                }
                final_len+=um[word[i]];
            }
            return final_len;
        }
    }
};