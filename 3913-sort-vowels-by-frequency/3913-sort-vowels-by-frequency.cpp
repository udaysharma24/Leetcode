class Solution {
public:
    string sortVowels(string s) {
        unordered_map<char,pair<int,int>> um;
        int place=0;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
            {
                if(um[s[i]].first==0)    // first represents frequency
                {
                    um[s[i]].second=place;  // second represents place
                    place++;
                }
                um[s[i]].first++;
            }
        }
        vector<tuple<char,int,int>> freq;
        freq.push_back({'a',um['a'].first,um['a'].second});
        freq.push_back({'e',um['e'].first,um['e'].second});
        freq.push_back({'i',um['i'].first,um['i'].second});
        freq.push_back({'o',um['o'].first,um['o'].second});
        freq.push_back({'u',um['u'].first,um['u'].second});
        sort(freq.begin(), freq.end(), [](const auto &a, const auto &b){
            if(get<1>(a)==get<1>(b))
                return get<2>(a)<get<2>(b);
            else
                return get<1>(a)>get<1>(b);
        });
        int index=0;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o' && s[i]!='u')
                continue;
            else
            {
                s[i]=get<0>(freq[index]);
                get<1>(freq[index])--;
                if(get<1>(freq[index])==0)
                    index++;
                else
                    continue;
            }
        }
        return s;
    }
};