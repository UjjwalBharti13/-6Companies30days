class Solution {
public:
  int dp[301];
   int helper(int i,string s,unordered_set<string>& st){
          if(i==s.size()) return 1;
            if(dp[i]!=-1) return dp[i];
             string temp ="";
             for(int j=i;j<s.size();j++){
                    temp+=s[j];
                    if(st.find(temp)!=st.end()){
                         if(helper(j+1,s,st)) return dp[i]=1;

                    }
             }
              return dp[i]= 0;
   }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
          for(auto ele : wordDict){
              st.insert(ele);
          }
          // memset(dp, -1, sizeof dp);
          
          // return helper(0,s,st);
             vector<int> dp(s.size()+1,0);
             dp[s.size()]=1;
              for(int i=s.size()-1;i>=0;i--){
                  string temp="";
                  for(int j=i;j<s.size();j++){
                     temp+=s[j];
                    if(st.find(temp)!=st.end() and dp[j+1]){
                        dp[i]=1;
                         break;

                    }
                       
                  }
                   
                    
              }
                return dp[0];
    }
};
