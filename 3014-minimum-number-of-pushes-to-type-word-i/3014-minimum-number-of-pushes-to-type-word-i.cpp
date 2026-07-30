class Solution {
public:
    int minimumPushes(string word) {
        if(word.length()<=8)
            return word.length();
        else{
            int len=word.length();
            int keys=1;
            int ans=0;
            while(len>8){
                ans+=(keys*8);
                keys++;
                len-=8;
            }
            ans+=(len*keys);
            return ans;
        }
    }
};