class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> vs;
        int len=0;
        for(int i=0; i<words.size(); i++){
            if(len==0){
                vs.push_back(words[i]);
                len+=(words[i].length());
            }
            else{
                int index=vs.size()-1;
                if(len<maxWidth && words[i].length()<=(maxWidth-1-len)){
                    vs[index]+=' ';
                    len++;
                    vs[index]+=words[i];
                    len+=(words[i].length());
                }
                else{
                    // cout<<"Yo ";
                    len=0;
                    vs.push_back(words[i]);
                    len+=(words[i].length());
                }
            }
            // cout<<len<<"\n";
        }
        // for(int i=0; i<vs.size(); i++){
        //     for(int j=0; j<vs[i].length(); j++){
        //         cout<<vs[i][j];
        //     }
        //     cout<<"\n";
        // }
        for(int i=0; i<vs.size(); i++){
            if(i==vs.size()-1){
                while(vs[i].length()<maxWidth){
                    vs[i].push_back(' ');
                }
            }
            else{
                bool has_space=false;
                while(vs[i].length()<maxWidth){
                    for(int j=0; j<vs[i].length(); j++){
                        if(vs[i][j]==' ')
                        {
                            has_space=true;
                            vs[i].insert(j,1,' ');
                            while(vs[i][j]==' ')
                                j++;
                        }
                        if(vs[i].length()==maxWidth)
                            break;
                    }
                    if(has_space==false)
                        vs[i].push_back(' ');
                }
            }
        }
        return vs;
    }
};