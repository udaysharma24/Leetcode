class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        if(is_sorted(s.begin(),s.end(),greater<char>()))
            return num;
        else{
            for(int i=0; i<s.length()-1; i++){
                int index=-1;
                int mx=int(s[i]-48);
                for(int j=s.length()-1; j>i; j--){
                    if(int(s[j]-48)>mx){
                        mx=int(s[j]-48);
                        index=j;
                    }
                }
                if(index!=-1){
                    swap(s[index],s[i]);
                    num=stoi(s);
                    return num;
                }
            }
        }
        return num;
    }
};