class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        int n=names.size();
        unordered_map<string,int> um;

        for(int i=0; i<n; i++){
            if(um[names[i]]==0)
                um[names[i]]++;
            else{
                int num=um[names[i]];

                while(um[names[i]+"("+to_string(num)+")"]>0){
                    num++;
                }

                // Update using the ORIGINAL name
                um[names[i]]=num+1;

                names[i]=names[i]+"("+to_string(num)+")";
                um[names[i]]++;
            }
        }
        return names;
    }
};