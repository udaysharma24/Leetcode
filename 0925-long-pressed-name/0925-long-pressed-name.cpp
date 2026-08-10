class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if(typed.length()<name.length())
            return false;
        int index=0;
        for(int i=0; i<name.length(); i++){
            bool flag=false;
            for(int j=index; j<typed.length(); j++){
                if(typed[j]==name[i]){
                    flag=true;
                    index=j+1;
                    break;
                }
                else if(j>0 && typed[j]==typed[j-1])
                    continue;
                else
                    return false;
            }
            if(flag==true)
                continue;
            else
                return false;
        }
        for(int i=index; i<typed.length(); i++){
            if(typed[i]!=typed[i-1])
                return false;
        }
        return true;
    }
};