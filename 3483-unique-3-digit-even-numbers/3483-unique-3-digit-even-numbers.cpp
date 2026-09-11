class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_set<int> us;
        int n=digits.size();
        for(int i=0; i<digits.size(); i++){
            for(int j=0; j<digits.size(); j++){
                if(j==i)
                    j++;
                if(j==n)
                    break;
                for(int k=0; k<digits.size(); k++){
                    while(k==i || k==j)
                        k++;
                    if(k==n)
                        break;
                    cout<<i<<" "<<j<<" "<<k<<"\t";
                    cout<<digits[i]*100+digits[j]*10+digits[k]<<"\n";
                    if(digits[i]!=0 && digits[k]%2==0){
                        us.insert(digits[i]*100+digits[j]*10+digits[k]);
                    }
                }
            }
        }
        return us.size();
    }
};