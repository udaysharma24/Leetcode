class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n=position.size();
        if(n==1)
            return 1;
        vector<int> newspeed;
        for(int i=0; i<n-1; i++){
            if(position[i+1]-position[i]<=distance)
                speed[i]=speed[i+1];
            else
                newspeed.push_back(speed[i]);
        }
        newspeed.push_back(speed[n-1]);
        int cnt=1;
        bool flag=true;
        for(int i=0; i<newspeed.size(); i++){
            cout<<newspeed[i]<<" ";
        }
        cout<<"\n";
        for(int i=newspeed.size()-1; i>0; i--){
            if(newspeed[i-1]>newspeed[i]){
                flag=true;
                newspeed[i-1]=newspeed[i];
            }
            else{
                cnt++;
                flag=false;
            }
        }
        return cnt;
    }
};