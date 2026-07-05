class Solution {
public:

    long long ans = 0;

    vector<vector<int>> adj;
    vector<bool> prime;

    // Returns {zeroPrimePaths, onePrimePaths}
    pair<long long,long long> dfs(int node, int parent)
    {
        long long zeroPrime;
        long long onePrime;

        //----------------------------
        // Path consisting of only this node
        //----------------------------
        if(prime[node])
        {
            zeroPrime = 0;
            onePrime = 1;
        }
        else
        {
            zeroPrime = 1;
            onePrime = 0;
        }

        //----------------------------
        // Process every child
        //----------------------------
        for(int child : adj[node])
        {
            if(child == parent)
                continue;

            auto childResult = dfs(child, node);

            long long childZero = childResult.first;
            long long childOne = childResult.second;

            //-----------------------------------
            // Count paths passing through node
            //-----------------------------------

            ans += zeroPrime * childOne;
            ans += onePrime * childZero;

            //-----------------------------------
            // Merge child into current node
            //-----------------------------------

            if(prime[node])
            {
                // Current node is prime

                onePrime += childZero;
            }
            else
            {
                // Current node is non-prime

                zeroPrime += childZero;
                onePrime += childOne;
            }
        }

        return {zeroPrime, onePrime};
    }

    long long countPaths(int n, vector<vector<int>>& edges)
    {
        //----------------------------
        // Build graph
        //----------------------------

        adj.resize(n+1);

        for(auto &e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        //----------------------------
        // Sieve
        //----------------------------

        prime.assign(n+1,true);

        prime[0]=false;
        prime[1]=false;

        for(int i=2;i*i<=n;i++)
        {
            if(prime[i])
            {
                for(int j=i*i;j<=n;j+=i)
                    prime[j]=false;
            }
        }

        //----------------------------
        // DFS from any node
        //----------------------------

        dfs(1,0);

        return ans;
    }
};