class Solution {
public:
    bool dfs(vector<vector<char>>& board, int i, int j, string word, int index,vector<vector<bool>>& visited){
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!=word[index])
            return false;
        else if(!visited[i][j] && board[i][j]==word[index] && index==word.length()-1){
            visited[i][j]=true;
            return true;
        }
        else if(!visited[i][j] && board[i][j]==word[index]){
            visited[i][j]=true;
            bool ans= (dfs(board,i+1,j,word,index+1,visited) || dfs(board,i,j+1,word,index+1,visited) || dfs(board,i-1,j,word,index+1,visited) || dfs(board,i,j-1,word,index+1,visited));
            visited[i][j]=false;
            return ans;
        }
        else
            return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(),false));
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(dfs(board,i,j,word,0,visited))
                    return true;
                else{
                    visited.assign(board.size(),vector<bool>(board[0].size(),false));
                    continue;
                }
            }
        }
        return false;
    }
};