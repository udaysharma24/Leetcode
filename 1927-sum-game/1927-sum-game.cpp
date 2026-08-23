class Solution {
public:
    bool sumGame(string num) {
        int half1=0,half2=0;
        int n=num.length();
        int q1=0,q2=0;
        for(int i=0; i<n/2; i++){
            if(num[i]=='?')
                q1++;
            if(num[i+(n/2)]=='?')
                q2++;
            if(num[i]!='?')
                half1+=int(num[i]-48);
            if(num[i+(n/2)]!='?')
                half2+=int(num[i+(n/2)]-48);
        }
        if((q1+q2)%2==1)
            return true; 
        else{
            int ans=half1+9*(q1/2)-(half2+9*(q2/2));
            if(ans==0)
                return false;
            else
                return true;
        }
        return false;
    }
};