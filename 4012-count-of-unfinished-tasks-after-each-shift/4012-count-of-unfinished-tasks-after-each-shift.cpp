class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int m=tasks.size();
        int n=shifts.size();

        vector<int> ans(n);

        vector<long long int> prefixsum(m);
        prefixsum[0]=tasks[0];

        for(int i=1; i<m; i++)
            prefixsum[i]=prefixsum[i-1]+tasks[i];

        long long start=0;

        for(int i=0; i<n; i++){

            long long target=start+shifts[i];

            int low=0;
            int high=m-1;

            while(low<=high){
                int mid=(low+high)/2;

                if(prefixsum[mid]<=target)
                    low=mid+1;
                else
                    high=mid-1;
            }

            int completed=high+1;

            if(completed==m){
                ans[i]=0;
                start=0;              // restart next shift from task 0
            }
            else{
                ans[i]=m-completed;
                start=target;         // current task is partially completed
            }
        }

        return ans;
    }
};