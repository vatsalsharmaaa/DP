// REC + MEMO
// class Solution {
// public:
    int dp[1001][1001];

//     bool solve(string &s,int i,int j){
//         if(i>=j){
//             return true;
//         }
//         if(dp[i][j]!=-1){
//             return dp[i][j];
//         }
//         if(s[i]==s[j]){
//             return dp[i][j]= solve(s,i+1,j-1);
//         }

//         return dp[i][j] = false;
//     }
//     string longestPalindrome(string s) {
//         int n= s.length();
//         memset(dp,-1,sizeof(dp));
//         int maxlen=INT_MIN;

//         int sp=0;
//         for(int i=0;i<n;i++){
//             for(int j=i;j<n;j++){
//                 if(solve(s,i,j)==true){
//                     if(j-i+1>maxlen){
//                     maxlen=j-i+1;
//                     sp=i;
//                   }
//                 }
//             }
//         }
//         return s.substr(sp,maxlen);
//     }
// };

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 0) return "";

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int maxlen = 1;   // at least 1 char palindrome
        int sp = 0;

        // L = length of substring
        for (int L = 1; L <= n; L++) {
            for (int i = 0; i + L - 1 < n; i++) {
                int j = i + L - 1;

                if (i == j) {
                    dp[i][j] = true;               // length 1
                }
                else if (i + 1 == j) {
                    dp[i][j] = (s[i] == s[j]);     // length 2
                }
                else {
                    dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]);
                }

                if (dp[i][j] && j - i + 1 > maxlen) {
                    maxlen = j - i + 1;
                    sp = i;
                }
            }
        }
        return s.substr(sp, maxlen);
    }
};
