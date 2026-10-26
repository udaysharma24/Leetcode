class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<int> indices(speed.size());
        iota(indices.begin(), indices.end(), 0);
        // 2. Sort the INDICES based on the values in the POSITION vector
        // Notice we capture 'position' by reference, and compare using indices 'i' and 'j'
        sort(indices.begin(), indices.end(), [&position](int i, int j) {
            return position[i] < position[j]; 
        });
        vector<int> newposition(position.size());
        vector<int> newspeed(speed.size());
        for(int i=0; i<speed.size(); i++){
            newposition[i]=position[indices[i]];
            newspeed[i]=speed[indices[i]];
        }
        int fleets=1;
        bool flag=true;
        for(int i=speed.size()-1; i>0; i--){
            double time1=(target-newposition[i])/double(newspeed[i]);
            double time2=(target-newposition[i-1])/double(newspeed[i-1]);
            double meetTime = (newposition[i] - newposition[i-1])/double(newspeed[i-1] - newspeed[i]);
            if(newspeed[i]<newspeed[i-1] && time1>=time2){
                flag=true;
                newspeed[i-1]=newspeed[i];
                newposition[i-1]=newposition[i];
            }
            else{
                flag=false;
                fleets++;
            }
        }
        return fleets;
    }
};