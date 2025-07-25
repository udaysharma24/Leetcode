class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen=0;
        int len=0;
        int l=0;
        int r=0;
        vector<int> arr(256, -1);
        while(r<(s.length()))
        {
            int index= int(s[r]);
            if(arr[index]!=-1)
            {
                if(arr[index]>=l)
                {
                    l=arr[index]+1;
                }
            }
            len=r-l+1;
            maxlen= max(len, maxlen);
            arr[index]= r;
            r++;
        }
        return maxlen; 
    }
};