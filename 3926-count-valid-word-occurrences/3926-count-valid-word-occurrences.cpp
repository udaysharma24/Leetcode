class Solution {
public:
    string resolve_joiner(string word){
        size_t pos = 0;
        while ((pos = word.find("--", pos)) != std::string::npos)
        {
            word.replace(pos, 2, " ");
            cout<<1<<"\n";
        }
        pos=0;
        while ((pos = word.find(" -", pos)) != std::string::npos)
        {
            word.replace(pos, 2, " ");
            cout<<2<<"\n";
        }
        pos=0;
        while ((pos = word.find("- ", pos)) != std::string::npos)
        {
            word.replace(pos, 2, " ");
            cout<<3<<"\n";
        }
        if(word[0]=='-')
            word[0]=' ';
        if(word[word.size()-1]=='-')
            word[word.size()-1]=' ';
        return word;
    }
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string strans=chunks[0];
        for(int i=1; i<chunks.size(); i++)
        {
            strans+=chunks[i];
        }
        //cout<<strans<<"\n";
        string finalstr= resolve_joiner(strans);
        unordered_map<string,int> um;
        string temp="";
        int i=0;
        while(finalstr[i]!='\0')
        {
            if(finalstr[i]!=' ')
                temp.push_back(finalstr[i]);
            else if(temp=="" && finalstr[i]==' ')
                continue;
            else
            {
                um[temp]++;
                temp="";
            }
            i++;
        }
        //cout<<temp<<"\n";
        if(temp!="")
            um[temp]++;
        //cout<<finalstr<<"\n";
        vector<int> ans(queries.size());
        for(int i=0; i<queries.size(); i++)
        {
            ans[i]=um[queries[i]];
        }
        return ans;
    }
};