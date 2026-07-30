class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> count(26,0); 
        for(int i=0; i<word.length(); i++){
            count[word[i]-'a']++;
        }
        sort(count.begin(),count.end());
        int minval=INT_MAX;
        int val=0;
        for(int i=0; i<26; i++){
            if(count[i]==0)
                continue;
            val=0;
            for(int j=0; j<26; j++){
                if(count[j]==0)
                    continue;
                else if(j<i)
                    val+=count[j];
                else if(count[j]-count[i]<=k)
                    continue;
                else
                    val+=(count[j]-count[i]-k);
            }
            minval=min(val,minval);
        }
        return minval;
        // int left=0;
        // int right=0;
        // int maxwindow=0;
        // int window=0;
        // int diff=0;
        // while(left<right && right<word.length()){
        //     int mx=*max_element(count.begin()+left,count.begin()+right+1);
        //     int mn=*min_element(count.begin()+left,count.begin()+right+1);
        //     diff=mx-mn;
        //     if(diff<=k){
        //         window=right-left+1;
        //         count[word[right]-'a']++;
        //         right++;
        //         maxwindow=max(window,maxwindow);
        //     }
        //     else{
        //         count[word[left]-'a']--;
        //         left++;
        //         maxwindow=max(window,maxwindow);
        //         window=right-left+1;
        //     }
        // }


    }
};