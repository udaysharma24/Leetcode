class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int m=arr1.size();
        int n=arr2.size();
        unordered_set<int> us;
        for(int i=0; i<m; i++){
            while(us.count(arr1[i])==0 && arr1[i]>0){
                us.insert(arr1[i]);
                arr1[i]/=10;
            }
        }
        int ans=0;
        for(int i=0; i<n; i++){
            while(us.count(arr2[i])==0 && arr2[i]>0){
                arr2[i]/=10;
            }
            if(arr2[i]>0){
                ans=max(ans,static_cast<int>(log10(arr2[i])+1));
            }
        }
        return ans;
    }
};