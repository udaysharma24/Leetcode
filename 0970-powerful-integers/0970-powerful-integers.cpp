class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        int i=0,j=0;
        set<int> s;
        vector<int> ans;
        if(x==1 && y==1){
            if(bound>=2)
                return {2};
            else
                return {};
        }
        else if(x==1){
            int j=0;
            int sum=pow(y,j)+1;
            while(sum<=bound){
                s.insert(sum);
                j++;
                sum=pow(y,j)+1;
            }
        }
        else if(y==1){
            int i=0;
            int sum=pow(x,i)+1;
            while(sum<=bound){
                s.insert(sum);
                i++;
                sum=pow(x,i)+1;
            }
        }
        else{
            int i=0,j=0;
            int sum=pow(x,i)+pow(y,j);
            while(sum<=bound){
                sum=pow(x,i)+pow(y,j);
                while(sum<=bound){
                    s.insert(sum);
                    j++;
                    sum=pow(x,i)+pow(y,j);
                }
                if(sum<=bound)
                    s.insert(sum);
                i++;
                j=0;
                sum=pow(x,i)+pow(y,j);
            }
        }
        auto it=s.begin();
        while(it!=s.end()){
            ans.push_back(*it);
            it++;
        }
        return ans;
    }
};