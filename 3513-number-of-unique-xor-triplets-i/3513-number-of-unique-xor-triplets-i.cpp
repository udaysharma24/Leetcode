class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if(n<3)
            return n;
        else{
            int temp=n;
            int cnt=0;
            while(temp>0){
                temp/=2;
                cnt++;
            }
            return pow(2,cnt);
        }
    }
};