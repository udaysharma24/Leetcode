class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int temp=*max_element(candidates.begin(),candidates.end());
        int n=0;
        while(temp>0){
            temp>>=1;
            n++;
        }
        vector<int> siz(n,0);
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<candidates.size(); j++){
                if(candidates[j]%2==1)
                    siz[i]++;
                candidates[j]>>=1;
            }
        }
        return *max_element(siz.begin(),siz.end());
    }
};