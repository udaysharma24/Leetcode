class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        bool low=false,high=false,digit=false,spec=false;
        int n=password.length();
        for(int i=0; i<n-1; i++){
            if(password[i]==password[i+1])
                return false;
            if(password[i]>=65 && password[i]<=90)
                low=true;
            if(password[i]>=97 && password[i]<=122)
                high=true;
            if(password[i]>=48 && password[i]<=57)
                digit=true;
            if(password[i]=='!' || password[i]=='@' || password[i]=='#' || password[i]=='$' || password[i]=='%' || password[i]=='^' || password[i]=='&' || password[i]=='*' || password[i]=='(' || password[i]==')' || password[i]=='-' || password[i]=='+')
                spec=true;
        }
        if(password[n-1]>=65 && password[n-1]<=90)
            low=true;
        if(password[n-1]>=97 && password[n-1]<=122)
            high=true;
        if(password[n-1]>=48 && password[n-1]<=57)
            digit=true;
        if(password[n-1]=='!' || password[n-1]=='@' || password[n-1]=='#' || password[n-1]=='$' || password[n-1]=='%' || password[n-1]=='^' || password[n-1]=='&' || password[n-1]=='*' || password[n-1]=='(' || password[n-1]==')' || password[n-1]=='-' || password[n-1]=='+')
            spec=true;
        return low&&high&&digit&&spec&&(n>=8);
    }
};