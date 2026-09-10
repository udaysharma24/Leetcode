class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        unordered_map<int,int> um1;
        unordered_map<int,int> um2;
        um1[3]=1;
        int num=3;
        int mx=*max_element(nums.begin(),nums.end());
        while(num<=mx && 2*num+1<=INT_MAX){
            um1[2*num+1]=num;
            num=2*num+1;
        }
        for(int i=0; i<n; i++){
            if(nums[i]==2)
                ans[i]=-1;
            else{
                if(um1.find(nums[i])!=um1.end())
                    ans[i]=um1[nums[i]];
                else{
                    int temp=nums[i];
                    string binary=format("{:b}",temp);
                    cout<<binary<<"\n";
                    for(int i=binary.length()-1; i>=0; i--){
                        if(binary[i]=='0' && binary[i+1]=='1'){
                            binary[i+1]='0';
                            break;
                        }
                    }
                    ans[i]=stoi(binary,nullptr,2);
                }
            }
        }
        return ans;
    }
};