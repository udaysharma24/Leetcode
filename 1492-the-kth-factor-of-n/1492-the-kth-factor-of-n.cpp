class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> v1;
        vector<int> v2;
        for(int i=1; i<=sqrt(n); i++){
            if(n%i==0){
                v1.push_back(i);
                if(i!=n/i)
                    v2.push_back(n/i);
            }
        }
        if(v1.size()+v2.size()<k)
            return -1;
        else if(k<=v1.size())
            return v1[k-1];
        else
            return v2[v2.size()+v1.size()-k];
    }
};