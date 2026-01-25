class Solution {
public:

    int dp[1001][1001];
    int n;

    int solve(vector<vector<int>>& pairs,int idx,int p){

        if(idx==n){
            return 0;
        }
        if(p!=-1 && dp[idx][p]!=-1){
            return dp[idx][p];
        }

        int take=0;
        if(p==-1|| pairs[p][1]<pairs[idx][0]){
            take= 1+ solve(pairs,idx+1,idx);
        }
        int skip= solve(pairs,idx+1,p);
        if(p!=-1)  //again p should not be -1 vrna fat jayega code
         dp[idx][p]= max(take,skip);

         return max(take,skip);

    }
    int findLongestChain(vector<vector<int>>& pairs) {
        n= pairs.size();
        memset(dp,-1,sizeof(dp));
        sort(begin(pairs),end(pairs));
        return solve(pairs,0,-1);
    }
};