class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int l=0;
        int r=people.size()-1;
        int boats=0;
        while(l<r){
            if(people[r]==limit){
                boats++;
                r--;
            }
            else if(people[r]+people[l]<=limit){
                boats++;
                r--;
                l++;
            }
            else if(people[r]+people[l]>limit){
                boats++;
                r--;
            }
        }
        if(l==r)
            boats++;
        return boats;
    }
};