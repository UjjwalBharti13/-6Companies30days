class Solution {
public:
    
    int LPS(string s){ //To find the longest palindrome of a given string
        
        if( s.size() == 1 ) return 1;
        int n = s.size();
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        
        for(int i = 0; i < n; i++) dp[i][i]=1;
         
        for(int i = 1; i < n; i++){
            for(int j = 0,k = i; j < n-i; j++){
                k = i+j;
                if( s[j] == s[k] )
                    dp[j][k] = dp[j+1][k-1]+2;
                else
                    dp[j][k] = max(dp[j][k-1],dp[j+1][k]);
            }
        }
        
        return dp[0][n-1];
    }
    int maxProduct(string s) {
        int ans = 0, len = s.size();
        // Generate all subsequences of the String
        for(int i = 1; i < pow(2,len-1); i++){
            string p = "", q = "";
            for(int j = 0; j < len; j++){
                if( i & 1<<j ) p+=s[j];
                else q+=s[j];
            }
            ans = max(ans, LPS(p)*LPS(q));
        }
        return ans;
    }
};
