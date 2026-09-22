class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        int maxscore=0;
        vector<int> maxval(n);
        maxval[0]=values[0];
        for(int i=1; i<n; i++){
            maxval[i]=max(maxval[i-1],values[i]+i);
        }
        for(int j=1; j<n; j++){
            maxscore=max(maxval[j-1]+values[j]-j,maxscore);
        }
        return maxscore;
    }
};