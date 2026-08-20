class Solution {
public:
    string smallestNumber(string pattern) {
        string s="";
        for(int i=1; i<=pattern.length()+1; i++){
            s.push_back(char(i+48));
        }
        cout<<s;
        int start=-1,end=-1;
        for(int i=0; i<pattern.length(); i++){
            if(pattern[i]=='D' && start==-1)
                start=i;
            if(pattern[i]=='I' && start!=-1)
                end=i+1;
            if(start!=-1 && end!=-1){
                reverse(s.begin()+start,s.begin()+end);
                start=-1;
                end=-1;
            }
        }
        if(start!=-1 && end==-1)
            reverse(s.begin()+start,s.end());
        return s;
    }
};