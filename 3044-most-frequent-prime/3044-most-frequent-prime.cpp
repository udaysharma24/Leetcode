class Solution {
public:
    bool isprime(int n){
        if(n<=1)
            return false;
        for(int i=2; i<=sqrt(n); i++){
            if(n%i==0)
                return false;
        }
        return true;
    }
    int mostFrequentPrime(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        unordered_map<int,int> um;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                string s="";
                s.push_back(char(mat[i][j]+48));
                int k=1;
                while(j-k>=0){
                    char temp=char(mat[i][j-k]+48);
                    s.push_back(temp);
                    int num=stoi(s);
                    if(isprime(num))
                        um[num]++;
                    k++;
                }
                k=1;
                s="";
                s.push_back(char(mat[i][j]+48));
                while(j+k<n){
                    char temp=char(mat[i][j+k]+48);
                    s.push_back(temp);
                    int num=stoi(s);
                    if(isprime(num))
                        um[num]++;
                    k++;
                }
                k=1;
                s="";
                s.push_back(char(mat[i][j]+48));
                while(i-k>=0){
                    char temp=char(mat[i-k][j]+48);
                    s.push_back(temp);
                    int num=stoi(s);
                    if(isprime(num))
                        um[num]++;
                    k++;
                }
                k=1;
                s="";
                s.push_back(char(mat[i][j]+48));
                while(i+k<m){
                    char temp=char(mat[i+k][j]+48);
                    s.push_back(temp);
                    int num=stoi(s);
                    if(isprime(num))
                        um[num]++;
                    k++;
                }
                k=1;
                s="";
                s.push_back(char(mat[i][j]+48));
                while(i-k>=0 && j-k>=0){
                    char temp=char(mat[i-k][j-k]+48);
                    s.push_back(temp);
                    int num=stoi(s);
                    if(isprime(num))
                        um[num]++;
                    k++;
                }
                k=1;
                s="";
                s.push_back(char(mat[i][j]+48));
                while(i+k<m && j+k<n){
                    char temp=char(mat[i+k][j+k]+48);
                    s.push_back(temp);
                    int num=stoi(s);
                    if(isprime(num))
                        um[num]++;
                    k++;
                }
                k=1;
                s="";
                s.push_back(char(mat[i][j]+48));
                while(i-k>=0 && j+k<n){
                    char temp=char(mat[i-k][j+k]+48);
                    s.push_back(temp);
                    int num=stoi(s);
                    if(isprime(num))
                        um[num]++;
                    k++;
                }
                k=1;
                s="";
                s.push_back(char(mat[i][j]+48));
                while(i+k<m && j-k>=0){
                    char temp=char(mat[i+k][j-k]+48);
                    s.push_back(temp);
                    int num=stoi(s);
                    if(isprime(num))
                        um[num]++;
                    k++;
                }
            }
        }
        int max_ele=-1;
        int max_freq=-1;
        for(const auto& pair:um){
            if(pair.second>max_freq){
                max_freq=pair.second;
                max_ele=pair.first;
            }
            else if(pair.second==max_freq)
                max_ele=max(max_ele,pair.first);
        }
        return max_ele;
    }
};