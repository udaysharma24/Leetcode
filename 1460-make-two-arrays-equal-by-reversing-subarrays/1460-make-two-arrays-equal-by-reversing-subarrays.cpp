class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> um1;
        unordered_map<int,int> um2;
        for(int i=0; i<arr.size(); i++){
            um1[arr[i]]++;
        }
        for(int i=0; i<target.size(); i++){
            um2[target[i]]++;
        }
        for(int i=0; i<target.size(); i++){
            if(um1[target[i]]!=um2[target[i]])
                return false;
        }
        return true;
    }
};