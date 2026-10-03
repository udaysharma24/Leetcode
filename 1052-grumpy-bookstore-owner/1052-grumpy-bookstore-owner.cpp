class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        int sum=0;
        int startindex=0;
        int endindex=minutes-1;
        for(int i=startindex; i<endindex+1; i++){
            if(grumpy[i]==1)
                sum+=customers[i];
        }
        int maxsum=sum;
        int mxstartindex=startindex;
        int mxendindex=endindex;
        while(endindex<n){
            if(grumpy[startindex]==1)
                sum-=customers[startindex];
            startindex++;
            endindex++;
            if(endindex==n)
                break;
            if(grumpy[endindex]==1)
                sum+=customers[endindex];
            if(sum>maxsum){
                maxsum=sum;
                mxstartindex=startindex;
                mxendindex=endindex;
            }
        }
        int temp=maxsum;
        for(int i=0; i<n; i++){
            if(grumpy[i]==0)
                maxsum+=customers[i];
        }
        cout<<mxstartindex<<" "<<mxendindex<<" "<<temp;
        return maxsum;
    }
};