class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s=to_string(n);
        sort(s.begin(),s.end());
        do{
            if(s[0]!='0'){
                int num=stoi(s);
                if(__builtin_popcount(num)==1)
                    return true;
            }
            else
                continue;
        }
        while(next_permutation(s.begin(),s.end()));
        return false;
    }
};