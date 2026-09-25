class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n=nums.size();
        vector<int> ans(n,0);
        int initxor=0;
        for(int i=0; i<n; i++){
            initxor^=nums[i];
        }
        int temp=initxor;
        vector<int> zeroindex;
        int i=0;
        while(i<maximumBit){
            if(initxor%2==0)
                zeroindex.push_back(i);
            i++;
            initxor/=2;
        }
        for(int i=0; i<n; i++){
            int z=zeroindex.size();
            ans[i]=0;
            for(int j=0; j<z; j++){
                if(ans[i]+pow(2,zeroindex[j])<pow(2,maximumBit))
                    ans[i]+=(pow(2,zeroindex[j]));
                else
                    break;
            }
            initxor=temp;
            initxor^=nums[n-i-1];
            temp=initxor;
            zeroindex.clear();
            int j=0;
            while(j<maximumBit){
                if(initxor%2==0)
                    zeroindex.push_back(j);
                j++;
                initxor/=2;
            }
        }
        return ans;
    }
};