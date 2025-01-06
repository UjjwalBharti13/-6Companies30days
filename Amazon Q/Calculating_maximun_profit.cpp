class Solution {
public:
int helper(vector<int>& prices,int i, int k,bool on,  vector<vector<vector<int>>>& dp){
        if(i==prices.size()or k==0) return 0;
         
         if(dp[i][k][on]!=-1) return dp[i][k][on];
         int ans = INT_MIN;

         ans = helper(prices,i+1,k,on,dp);// avoid
         // not avoid 
         if(on){
            ans = max(ans,prices[i]+helper(prices,i+1,k-1,false,dp));
         }else{
            if(k>0){
                ans = max(ans,helper(prices,i+1,k,true,dp)-prices[i]);
            }
         }
           return dp[i][k][on]=ans;

}
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k+1, vector<int>(2, -1)));
         return helper(prices,0,k,false,dp);
    }
};
