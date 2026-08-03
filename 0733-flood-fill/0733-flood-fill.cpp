class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        queue<pair<int,int>> qp;
        qp.push({sr,sc});
        int startcolor=image[sr][sc];
        if(startcolor==color)
            return image;
        image[sr][sc]=color;
        while(!qp.empty()){
            int tempx=qp.front().first;
            int tempy=qp.front().second;
            qp.pop();
            if(tempx+1<m && tempy<n && image[tempx+1][tempy]==startcolor){
                qp.push({tempx+1,tempy});
                image[tempx+1][tempy]=color;
            }
            if(tempx<m && tempy+1<n && image[tempx][tempy+1]==startcolor){
                qp.push({tempx,tempy+1});
                image[tempx][tempy+1]=color;
            }
            if(tempx-1>=0 && tempy>=0 && image[tempx-1][tempy]==startcolor){
                qp.push({tempx-1,tempy});
                image[tempx-1][tempy]=color;
            }
            if(tempx>=0 && tempy-1>=0 && image[tempx][tempy-1]==startcolor){
                qp.push({tempx,tempy-1});
                image[tempx][tempy-1]=color;
            }
        }
        return image;
    }
};