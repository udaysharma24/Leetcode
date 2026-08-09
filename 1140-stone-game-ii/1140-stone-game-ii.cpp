class Solution {

public:

    vector<vector<vector<int>>> dp;
    vector<int> prefix;

    int optimal(vector<int>& piles, int X, int M, char chance, int index){

        if(index == piles.size())
            return 0;

        M = max(M, X);

        int turn;

        if(chance == 'A')
            turn = 0;
        else
            turn = 1;

        if(dp[index][M][turn] != -1)
            return dp[index][M][turn];

        int alice_stones;

        if(chance == 'B'){

            alice_stones = INT_MAX;

            for(int i=1; i<=2*M && index+i<=piles.size(); i++){

                alice_stones = min(
                    optimal(piles, i, M, 'A', index+i),
                    alice_stones
                );
            }
        }

        else if(chance == 'A'){

            alice_stones = 0;

            for(int i=1; i<=2*M && index+i<=piles.size(); i++){

                int stones = prefix[index+i] - prefix[index];

                alice_stones = max(
                    stones + optimal(piles, i, M, 'B', index+i),
                    alice_stones
                );
            }
        }

        return dp[index][M][turn] = alice_stones;
    }

    int stoneGameII(vector<int>& piles) {

        int n = piles.size();

        prefix.resize(n+1,0);

        for(int i=0; i<n; i++)
            prefix[i+1] = prefix[i] + piles[i];

        dp.resize(n, vector<vector<int>>(n+1, vector<int>(2,-1)));

        int M = 1;
        int index = 0;

        int alice_stones = 0;

        for(int i=1; i<=2*M && index+i<=piles.size(); i++){

            int stones = prefix[index+i] - prefix[index];

            alice_stones = max(
                stones + optimal(piles, i, M, 'B', index+i),
                alice_stones
            );
        }

        return alice_stones;
    }
};