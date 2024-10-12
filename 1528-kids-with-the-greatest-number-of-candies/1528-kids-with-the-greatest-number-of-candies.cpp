class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result(candies.size(),false);
        for(int i=0; i<candies.size(); i++)
        {
            if(candies[i]+extraCandies>=(*max_element(candies.begin(),candies.end())))
                result[i]=true;
        }
        return result;
    }
};