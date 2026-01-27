class Solution {
public:
int n;int m;
int dp[1001][1001];

    int solve(int idx1,int idx2,string &text1, string &text2)
    {
        if(idx1>=n || idx2>=m){
            return 0;

        }
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];

        if(text1[idx1]==text2[idx2]){
            return dp[idx1][idx2]=1+solve(idx1+1,idx2+1,text1,text2);
        }
        else{
        int skip1= solve(idx1+1,idx2,text1,text2);
        int skip2= solve(idx1,idx2+1,text1,text2);
            return dp[idx1][idx2]= max(skip1,skip2);
     }

    }

    int longestCommonSubsequence(string text1, string text2) {
        n=text1.length();
        m=text2.length();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,text1,text2);
    }
};