class Solution {
public:
    int N,M,K;
    int MOD= 1e9+7;
    int dp[51][51][101];

    int solve(int idx,int searchCost , int maxSofar){

        
        if(idx==N){
            if(searchCost==K)
            {
             return 1;
            }

            return 0;
        }
        
        if(maxSofar!=-1 && dp[idx][searchCost][maxSofar]!=-1){
            return dp[idx][searchCost][maxSofar];
        }

        int  result=0;

        for (int i = 1; i <= M; i++) {
    if (i > maxSofar) {
        result = (result + solve(idx + 1, searchCost + 1, i)) % MOD; //cost+1 and update max by i
    } else {
        result = (result + solve(idx + 1, searchCost, maxSofar)) % MOD;
    }
}


        if(maxSofar!=-1){
            dp[idx][searchCost][maxSofar]= result%MOD;
        }
        return result%MOD;
    }
    int numOfArrays(int n, int m, int k) {
        N=n;
        M=m;
        K=k;
        memset(dp,-1,sizeof(dp));

        return solve(0,0,-1);

    }
};