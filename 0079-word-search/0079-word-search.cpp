class Solution {
public:
    bool backtrack(int x, int y, string current, vector<vector<char>>& board, string word, vector<vector<bool>>& visited){
        bool flag=false;
        if(current==word)
            return true;
        if(current.length()>word.length() || (current!=word && current.length()==word.length()))
            return false;
        if(x>=board.size() || y>=board[0].size() || x<0 || y<0)
            return false;
        if(board[x][y] != word[current.length()])
            return false;
        if(visited[x][y])
            return false;
        if(!visited[x][y]){ //Take
            current.push_back(board[x][y]);
            visited[x][y]=true;
            flag=backtrack(x+1,y,current,board,word,visited) || backtrack(x,y+1,current,board,word,visited) || backtrack(x-1,y,current,board,word,visited) || backtrack(x,y-1,current,board,word,visited);
        }
        if(visited[x][y]){
            current.pop_back();
            visited[x][y]=false;
        }
        return flag;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        if(word.length()>m*n)
            return false;
        bool flag=false;
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                flag=backtrack(i,j,"",board,word,visited);
                if(flag==true)
                    return flag;
            }
        }
        return flag;
    }
};