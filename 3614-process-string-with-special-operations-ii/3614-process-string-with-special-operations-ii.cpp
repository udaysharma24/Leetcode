class Solution {
public:
    char processStr(string s, long long k) {
        int n=s.length();
        long long int sim_size=0;
        for(int i=0; i<n; i++){
            if(s[i]=='*'){
                if(sim_size!=0)
                    sim_size--;
            }
            else if(s[i]=='%'){
                continue;
            }
            else if(s[i]=='#'){
                sim_size*=2;
            }
            else{
                sim_size++;
            }
        }
        cout<<sim_size<<"\n";
        if(k+1>sim_size)
            return '.';
        long long int cur_size=sim_size;
        for(int i=n-1; i>=0; i--){
            if(s[i]=='*'){
                cur_size++;
            }
            else if(s[i]=='%'){
                k=cur_size-k-1;
            }
            else if(s[i]=='#'){
                cur_size/=2;
                if(k>=cur_size)
                    k-=cur_size;
            }
            else{
                if(k==cur_size-1)
                    return s[i];
                cur_size--;
            }
        }
        return ' ';
    }
};