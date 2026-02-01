struct Job{
    int s , e , p;
};

class Solution {
public:
    int solve(int i , vector<Job>&jobs , vector<int>&dp){
        if(i == jobs.size())return 0;

        if(dp[i] != -1)return dp[i];

        int skip = solve(i+1,jobs,dp);

        int next = i+1;
        while(next < jobs.size() && jobs[next].s < jobs[i].e){
            //invalid or overlap
            next++;
        }

        int take = jobs[i].p + solve(next,jobs,dp);

        return dp[i] =  max(skip,take);
    }

    int jobScheduling(vector<int>& start, vector<int>& end, vector<int>& profit) {
        int n = profit.size();
        vector<Job>jobs(n);
        for(int i = 0 ; i<n ; i++){
            jobs[i] = {start[i], end[i], profit[i]};
        }

        sort(jobs.begin(),jobs.end() , [](Job&a , Job& b){
            return a.s<b.s;
        });

        vector<int>dp(n,-1);

        return solve(0,jobs,dp);
    }
};