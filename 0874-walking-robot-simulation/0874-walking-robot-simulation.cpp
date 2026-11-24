class Solution {
public:
    struct PairHash {
        template <class T1, class T2>
        std::size_t operator()(const std::pair<T1, T2>& p) const {
            auto h1 = std::hash<T1>{}(p.first);
            auto h2 = std::hash<T2>{}(p.second);
            // Combine hashes to reduce collisions (e.g., so {1, 2} != {2, 1})
            return h1 ^ (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));
        }
    };
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map<pair<int,int>,int,PairHash> ump;
        int n=obstacles.size();
        for(int i=0; i<n; i++){
            int x=obstacles[i][0];
            int y=obstacles[i][1];
            ump[{x,y}]++;
        }
        pair<int,int> p={0,0};
        bool isup=true;
        bool isdown=false;
        bool isleft=false;
        bool isright=false;
        int ans=0;
        for(int i=0; i<commands.size(); i++){
            if(commands[i]>0 && isup){
                int tempy=p.second+1;
                for(int j=1; j<=commands[i]; j++){
                    tempy=p.second+j;
                    if(ump.find({p.first,tempy})!=ump.end()){
                        tempy--;
                        break;
                    }
                }
                p={p.first,tempy};
                ans=max(ans,(p.first*p.first)+(tempy*tempy));
            }
            else if(commands[i]>0 && isdown){
                int tempy=p.second-1;
                for(int j=1; j<=commands[i]; j++){
                    tempy=p.second-j;
                    if(ump.find({p.first,tempy})!=ump.end()){
                        tempy++;
                        break;
                    }
                }
                p={p.first,tempy};
                ans=max(ans,(p.first*p.first)+(tempy*tempy));
            }
            else if(commands[i]>0 && isright){
                int tempx=p.first+1;
                for(int j=1; j<=commands[i]; j++){
                    tempx=p.first+j;
                    if(ump.find({tempx,p.second})!=ump.end()){
                        tempx--;
                        break;
                    }
                }
                ans=max(ans,(p.second*p.second)+(tempx*tempx));
                p={tempx,p.second};
            }
            else if(commands[i]>0 && isleft){
                int tempx=p.first-1;
                for(int j=1; j<=commands[i]; j++){
                    tempx=p.first-j;
                    if(ump.find({tempx,p.second})!=ump.end()){
                        tempx++;
                        break;
                    }
                }
                p={tempx,p.second};
                ans=max(ans,(p.second*p.second)+(tempx*tempx));
            }
            else if(commands[i]==-2){
                if(isup){
                    isup=false;
                    isleft=true;
                }
                else if(isdown){
                    isdown=false;
                    isright=true;
                }
                else if(isleft){
                    isleft=false;
                    isdown=true;
                }
                else if(isright){
                    isright=false;
                    isup=true;
                }
            }
            else if(commands[i]==-1){
                if(isup){
                    isup=false;
                    isright=true;
                }
                else if(isdown){
                    isdown=false;
                    isleft=true;
                }
                else if(isleft){
                    isleft=false;
                    isup=true;
                }
                else if(isright){
                    isright=false;
                    isdown=true;
                }
            }
        }
        return ans;
    }
};