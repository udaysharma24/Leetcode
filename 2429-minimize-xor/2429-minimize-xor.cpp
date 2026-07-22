class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int num2_setbits= __builtin_popcount(num2);
        int num1_setbits= __builtin_popcount(num1);
        if(num1_setbits==num2_setbits)
            return num1;
        else{
            int diff=abs(num1_setbits-num2_setbits);
            int temp=0;
            int temp1=num1;
            if(num1_setbits>num2_setbits){
                int i=0;
                int cnt=0;
                while(cnt<diff){
                    if(temp1%2==1){
                        temp+=(pow(2,i));
                        cnt++;
                    }
                    i++;
                    temp1/=2;
                }
            }
            else if(num1_setbits<num2_setbits){
                int i=0;
                int cnt=0;
                while(cnt<diff){
                    if(temp1%2==0){
                        temp+=(pow(2,i));
                        cnt++;
                    }
                    i++;
                    temp1/=2;
                }
            }
            cout<<temp<<" "<<num1<<" "<<(temp^num1)<<"\n";
            return (temp^num1);
        }
    }
};