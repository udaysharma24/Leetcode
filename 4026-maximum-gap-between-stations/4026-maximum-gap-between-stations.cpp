class Solution {
public:
    int maximumGap(string skill, string station) {
        vector<int> assignmentr(skill.length(),-1);
        vector<int> assignmentl(skill.length(),-1);
        int l=0;
        int r=skill.length()-1;
        int n=skill.length();
        for(int i=0; i<station.length() && l<skill.length(); i++){
            if(skill[l]==station[i]){
                assignmentl[l]=i;
                l++;
            }
        }
        for(int i=station.length()-1; i>=0 && r>=0; i--){
            if(skill[r]==station[i]){
                assignmentr[r]=i;
                r--;
            }
        }
        int maxval=0;
        for(int i=0; i<n-1; i++){
            maxval=max(maxval,assignmentr[i+1]-assignmentl[i]);
        }
        return maxval;
    }
};