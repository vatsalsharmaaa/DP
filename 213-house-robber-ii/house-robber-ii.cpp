class Solution {
public:
    int dp[101];
    int solve(vector<int>&nums,int i,int n){
        if(i>n) return 0;

        if(dp[i]!=-1) return dp[i];

        int steal= nums[i]+solve(nums,i+2,n);
        int pass=solve(nums,i+1,n);
        return dp[i]=max(pass,steal);
    }
    int rob(vector<int>& nums) {
        int n= nums.size();
        if(n==1) return nums[0];

        if(n==2)
        return max(nums[0],nums[1]);

        memset(dp,-1,sizeof(dp));

        //case1 pehle ghar ko lele
        
        int taking_1st=solve(nums,0,n-2);
        memset(dp,-1,sizeof(dp));

        //case2 pehla ghar nahi lia
        int taking_2nd = solve(nums,1,n-1);

        return max(taking_1st,taking_2nd);
    }
};