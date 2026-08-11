class Solution {
public:
    string maxValue(string n, int x) {
        if(n[0]=='-'){
            int temp=int(n[1]-48);
            if(x<temp){
                n.insert(n.begin()+1,char(x+48));
                return n;
            }
            else{
                int pos=n.length();
                for(int i=1; i<n.length(); i++){
                    if(int(n[i]-48)>x){
                        pos=i;
                        break;
                    }
                }
                n.insert(n.begin()+pos, char(x+48));
                return n;
            }
        }
        else{
            int pos;
            int temp=int(n[0]-48);
            if(x<temp)
                pos=n.length();
            else
                pos=0;
            for(int i=0; i<n.length(); i++){
                if(int(n[i]-'0')<x){
                    pos=i;
                    break;
                }
            }
            n.insert(n.begin()+pos,char(x+48));
            return n;
        }
    }
};