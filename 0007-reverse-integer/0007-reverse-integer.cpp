class Solution {
public:
    long long int reverse(long long int x) {
        long long int temp=x,sum=0;
        deque<int> d;
        if(temp<0)
            temp=-temp;
        while(temp>0)
        {
            d.push_back(temp%10);
            temp/=10;
        }
        if(x<0)
        {
            while(d.empty()==0)
            {
                sum+=(d.front()*pow(10,d.size()-1));
                d.pop_front();
            }
            sum=-sum;
            if(sum<INT_MIN)
                return 0;
        }
        else
        {
            while(d.empty()==0)
            {
                sum+=(d.front()*pow(10,d.size()-1));
                d.pop_front();
            }
            if(sum>INT_MAX)
                return 0;
        }
        return sum;
    }
};