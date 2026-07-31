class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.length();
        if(s[n-1]=='1')
            return false;
        else{
            queue<int> q1;
            queue<int> q2;
            vector<bool> visited1(n,false);
            vector<bool> visited2(n,false);
            q1.push(0);
            q2.push(n-1);
            visited1[0]=true;
            visited2[n-1]=true;
            while(!q1.empty() && !q2.empty()){
                int temp1=q1.front();
                int temp2=q2.front();
                q1.pop();
                q2.pop();
                for(int j=minJump; j<=maxJump; j++){
                    if(temp1+j<s.length() && s[temp1+j]=='0' && !visited1[temp1+j]){
                        q1.push(temp1+j);
                        if(temp1+j==n-1)
                            return true;
                        visited1[temp1+j]=true;
                    }
                }
                for(int j=minJump; j<=maxJump; j++){
                    if(temp2-j>=0 && s[temp2-j]=='0' && !visited2[temp2-j]){
                        q2.push(temp2-j);
                        if(temp2-j==0)
                            return true;
                        if(visited1[temp2-j])
                            return true;
                        visited2[temp2-j]=true;
                    }
                }
            }
            return false;
        }
    }
};