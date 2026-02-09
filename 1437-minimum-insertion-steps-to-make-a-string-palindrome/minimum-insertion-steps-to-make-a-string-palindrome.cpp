// class Solution {
// public:
//     int minInsertions(string str) {
//         string rev = str;
//         reverse(rev.begin(), rev.end());
//         int n = str.size();

//         // LCS table
//         vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

//         for (int i = 1; i <= n; ++i) {
//             for (int j = 1; j <= n; ++j) {
//                 if (str[i - 1] == rev[j - 1])
//                     dp[i][j] = 1 + dp[i - 1][j - 1];
//                 else
//                     dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//             }
//         }

//         return n - dp[n][n]; // Minimum insertions = total length - LPS length
//     }
// };

// class Solution {
// public:
//     int dp[501][501];
//     int n;
//     int solve(int i,int j,string &s){

//         if(i>=j) return 0;
//         if(dp[i][j]!=-1){
//             return dp[i][j];
//         }

//         if(s[i]==s[j]){
//             return dp[i][j]=solve(i+1,j-1,s);
//         }
//         else{
//             int take1= 1+ solve(i+1,j,s);
//             int take2= 1+solve(i,j-1,s);

//             return dp[i][j]=min(take1,take2);
//         }
//     }
//     int minInsertions(string str) {
//         n=str.size();
//         memset(dp,-1,sizeof(dp));
//         return solve(0,n-1,str);
//     }
// };


//bottom up tc=0(n*n);
class Solution {
public:

    int minInsertions(string str) {
      int n= str.size();
      vector<vector<int>>dp(n,vector<int>(n));

      for(int l=2;l<=n;l++){
        for(int i=0;i<n-l+1;i++){
            int j=i+l-1;

           

            if(str[i]==str[j]){
                dp[i][j]= dp[i+1][j-1];
            }
            else{
                dp[i][j]= 1+min(dp[i+1][j],dp[i][j-1]);
            }
        }
      }
      return dp[0][n-1];
    }
};


