class Solution {
public:
    string largestOddNumber(string num) {
        string s="";
        bool flag=false;
        for(int i=num.size()-1; i>=0; i--)
        {
            int n= int(num[i]-48);
            if(n%2==1 || flag==true)
            {
                s+=num[i];
                flag=true;
            }
        }
        reverse(s.begin(), s.end());
        return s;
    }
};