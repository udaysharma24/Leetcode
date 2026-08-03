class Solution {
public:
    int twoEggDrop(int n) {
        int f=0;
        int val=(f*(f+1))/2;
        while(val<n){
            f++;
            val=(f*(f+1))/2;
        }
        return f;
    }
};