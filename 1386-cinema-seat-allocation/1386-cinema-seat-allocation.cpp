class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(),reservedSeats.end(),[](vector<int>& a, vector<int>& b){
            if(a[0]==b[0])
                return a[1]<b[1];
            return a[0]<b[0];
        });
        unordered_map<int,bool> um;
        unordered_map<int,bool> uml;
        unordered_map<int,bool> umu;
        unordered_map<int,bool> umm;
        for(int i=0; i<reservedSeats.size(); i++){
            int row=reservedSeats[i][0];
            int col=reservedSeats[i][1];
            um[row]=true;
            if(col!=1 && col<=5)
                uml[row]=true;
            if(col!=10 && col>=6)
                umu[row]=true;
            if(col>=4 && col<=7)
                umm[row]=true;
        }
        int ans=2*n;
        for(const auto &[row,reserved]:um){
            if(uml[row] && umu[row] && umm[row])
                ans-=2;
            else if(uml[row] && umu[row])
                ans--;
            else if(uml[row] && umm[row])
                ans--;
            else if(umm[row] && umu[row])
                ans--;
            else if(uml[row] || umm[row] || umu[row])
                ans--;
        }
        return ans;
    }
};