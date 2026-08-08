class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        queue<pair<int,int>> qp;
        vector<vector<bool>> visited(rows, vector<bool>(cols,false));
        vector<vector<int>> ans;
        qp.push({rCenter,cCenter});
        visited[rCenter][cCenter]=true;
        while(!qp.empty()){
            pair<int,int> temp=qp.front();
            int temp1=temp.first;
            int temp2=temp.second;
            vector<int> newvec;
            newvec.push_back(temp1);
            newvec.push_back(temp2);
            ans.push_back(newvec);
            qp.pop();
            if(temp1>0 && !visited[temp1-1][temp2]){
                qp.push({temp1-1,temp2});
                visited[temp1-1][temp2]=true;
            }
            if(temp2>0 && !visited[temp1][temp2-1]){
                qp.push({temp1,temp2-1});
                visited[temp1][temp2-1]=true;
            }
            if(temp1<rows-1 && !visited[temp1+1][temp2]){
                qp.push({temp1+1,temp2});
                visited[temp1+1][temp2]=true;
            }
            if(temp2<cols-1 && !visited[temp1][temp2+1]){
                qp.push({temp1,temp2+1});
                visited[temp1][temp2+1]=true;
            }
        }
        return ans;
    }
};