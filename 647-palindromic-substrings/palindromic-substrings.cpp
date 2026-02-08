// class Solution {
// public:
// int dp[1001][1001];
//     bool checkPalindrome(int i,int j,string &s)
//     {
//         if(i>j) return true;
//         if(dp[i][j]!=-1) return true;
//         if(s[i]==s[j]){
            
//             return dp[i][j]=checkPalindrome(i+1,j-1,s);
//         }
//         return false;
//     }
//     int countSubstrings(string s) {
//         memset(dp,-1,sizeof(dp));

//         // dp[i][j]=-1 not solved yet
//         // dp[i][j] =1 true
//         // dp[i][j] =0 fals e
//         int n= s.size();
//         int count=0;
//         for(int i=0;i<n;i++){
//             for(int j=i;j<n;j++){
//                 if(checkPalindrome(i,j,s))
//                 count++;
//             }
//         }
//         return count;
//     }
// };
class Solution {
public:
  int countSubstrings(string s) {
      int n = s.length();
      vector<vector<bool>>dp(n,vector<bool>(n,false));
      int count=0;
      for(int L=1;L<=n;L++){
        for(int i=0;i+L-1<n;i++){
            int j=i+L-1;

            if(i==j){   //1 length string always true
                dp[i][j]=true;

            }
            else if(i+1 ==j){   // 2 length
                dp[i][j]= (s[i]==s[j]);
            }
            else{
                dp[i][j]=(s[i]==s[j]&&dp[i+1][j-1]); //generic case
            }
            if(dp[i][j]==true){
                count++;
            }
        }
      }
      return count;
    }
};