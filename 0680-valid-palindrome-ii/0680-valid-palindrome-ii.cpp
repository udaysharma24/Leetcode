class Solution {
public:
    bool validPalindrome(string s) {
        int n=s.length();
        if(n<=2)
            return true;
        int l=0;
        int r=n-1;
        bool flag1=true,flag2=true;
        while(l<r){
            if(s[l]==s[r]){
                l++;
                r--;
            }
            else if(flag1==true){
                if(s[r-1]==s[l])
                    r--;
                else if(s[l+1]==s[r])
                    l++;
                else{
                    flag1=false;
                    flag2=false;
                    break;
                }
                flag1=false;
            }
            else if(flag1==false){
                flag2=false;
                break;
            }
        }
        l=0;
        r=n-2;
        bool flag3=true;
        while(l<r){
            if(s[l]==s[r]){
                l++;
                r--;
            }
            else if(flag3==true){
                flag3=false;
                break;
            }
        }
        l=1;
        r=n-1;
        bool flag4=true;
        while(l<r){
            if(s[l]==s[r]){
                l++;
                r--;
            }
            else if(flag4==true){
                flag4=false;
                break;
            }
        }
        l=0;
        r=n-1;
        bool flag5=true,flag6=true;
        while(l<r){
            if(s[l]==s[r]){
                l++;
                r--;
            }
            else if(flag5==true){
                if(s[l+1]==s[r])
                    l++;
                else if(s[r-1]==s[l])
                    r--;
                else{
                    flag5=false;
                    flag6=false;
                    break;
                }
                flag5=false;
            }
            else if(flag5==false){
                flag6=false;
                break;
            }
        }
        if(flag2==true || flag3==true || flag4==true || flag6==true)
            return true;
        else
            return false;
    }
};