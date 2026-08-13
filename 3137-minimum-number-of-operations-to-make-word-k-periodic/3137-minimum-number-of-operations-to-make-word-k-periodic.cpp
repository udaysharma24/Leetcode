class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string,int> um;
        for(int i=0; i<word.length(); i+=k){
            string substring=word.substr(i,k);
            um[substring]++;
        }
        string maxrep="";
        int maxlen=0;
        for(const auto& [key,value]:um){
            if(value>maxlen){
                maxlen=max(maxlen,value);
                maxrep=key;
            }
        }
        int operations=0;
        for(int i=0; i<word.length(); i+=k){
            string substring=word.substr(i,k);
            if(substring!=maxrep)
                operations++;
        }
        return operations;
    }
};