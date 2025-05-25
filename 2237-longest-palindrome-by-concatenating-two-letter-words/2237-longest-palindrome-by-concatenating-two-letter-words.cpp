class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int len=0;
        unordered_set<string> s;
        unordered_map<string, int> um;
        for(int i=0; i<words.size(); i++)
        {
            s.insert(words[i]);
            um[words[i]]++;
        }
        bool flagodd= false;
        auto it= s.begin();
        while(it!=s.end())
        {
            if((*it)[0]==(*it)[1])
            {
                if(um[*it]%2==1 && flagodd==false)
                {
                    flagodd= true;
                    len+=(2*um[*it]);
                }
                else if(um[*it]%2==1 && flagodd==true)
                {
                    len+=(2*(um[*it]-1));
                }
                else if(um[*it]%2==0)
                {
                    len+=(2*um[*it]);
                }
            }
            it++;
        }
        it= s.begin();
        while(it!= s.end())
        {
            string rev= *it;
            reverse(rev.begin(), rev.end());
            if(rev==*it)
            {
                it++;
                continue;
            }
            len+=(2*(min(um[*it], um[rev])));
            it++;
        }
        return len;
    }
};