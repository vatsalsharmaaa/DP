class Solution {
public:

int n;
typedef long long ll;
ll dp[100001][2];

    ll solve(int idx,vector<int>&nums,bool flag)
    {
        if(idx>=n){
            return 0;
        }

        if(dp[idx][flag]!=-1){
            return dp[idx][flag];
        }
        ll skip= solve(idx+1,nums,flag);

        ll val=nums[idx];
        if(flag==false){
            val=-val;
        } 

        ll take = solve(idx+1,nums,!flag)+val;

        return dp[idx][flag]=max(take,skip);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        n=nums.size();
        memset(dp,-1,sizeof(dp));
       return  solve(0,nums,true);
        
    }
};