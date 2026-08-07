class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> dp(numCourses, vector<bool>(numCourses,false));
        int n=prerequisites.size();
        for(int i=0; i<n; i++){
            int parent=prerequisites[i][0];
            int child=prerequisites[i][1];
            dp[parent][child]=true;
        }
        for(int i=0; i<numCourses; i++){
            for(int j=0; j<numCourses; j++){
                for(int k=0; k<numCourses; k++){
                    if(dp[i][j]==true && dp[j][k]==true)
                        dp[i][k]=true;
                }
            }
        }
        int qsize=queries.size();
        vector<bool> ans(qsize,false);
        for(int i=0; i<qsize; i++){
            int parent=queries[i][0];
            int child=queries[i][1];
            if(dp[parent][child]==true)
                ans[i]=true;
        }
        return ans;
    }
};