class Solution {
public:
    long long sideSum(long long peak, long long len) {
        if (len < peak) {
            return len * (2 * peak - len - 1) / 2;
        }
        return (peak - 1) * peak / 2 + (len - (peak - 1));
    }
    int maxValue(int n, int index, int maxSum) {
        if(n==1)
            return maxSum;
        int low=1;
        int high=maxSum;
        int ans=1;
        while(low<=high){
            int mid=(low+high)/2;
            long long int sum=(long long)mid;
            // Left side
            sum += sideSum(mid, index);

            // Right side
            sum += sideSum(mid, n - index - 1);

            if(sum>maxSum)
                high=mid-1;
            else{
                ans=max(mid,ans);
                low=mid+1;
            }
        }
        return ans;
    }
};