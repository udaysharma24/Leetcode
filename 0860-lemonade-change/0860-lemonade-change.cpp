class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n=bills.size();
        if(bills[0]!=5)
            return false;
        else{
            int total=5;
            unordered_map<int,int> um;
            um[5]=1;
            for(int i=1; i<n; i++){
                int change=bills[i]-5;
                if(total>=change){
                    while(change>=20 && um[20]>0){
                        change-=20;
                        um[20]--;
                    }
                    while(change>=10 && um[10]>0){
                        change-=10;
                        um[10]--;
                    }
                    while(change>=5 && um[5]>0){
                        change-=5;
                        um[5]--;
                    }
                    if(change>0)
                        return false;
                    else
                        um[bills[i]]++;
                }
                else
                    return false;
                total+=5;
            }
            return true;
        }
    }
};