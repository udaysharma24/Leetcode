class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> v;
        int cnt=k-1;
        int start=1;
        int end=n;
        int freq=0;
        while(freq<=cnt){
            if(freq%2==0){
                v.push_back(start);
                start++;
            }
            else{
                v.push_back(end);
                end--;
            }
            freq++;
        }
        if(cnt%2==1){
            while(v.size()<n){
                v.push_back(end);
                end--;
            }
        }
        else{
            while(v.size()<n){
                v.push_back(start);
                start++;
            }
        }
        return v;
    }
};