class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i1,i2;
        for(int i=0; i<numbers.size(); i++){
            i1=i+1;
            if(binary_search(numbers.begin(),numbers.end(),target-numbers[i])){
                auto it=lower_bound(numbers.begin(),numbers.end(),target-numbers[i]);
                int index=it-numbers.begin();
                i2=index+1;
                break;
            }
        }
        if(i1==i2)
            i2++;
        return {i1,i2};
    }
};