class Solution {
public:
 // Approach 
 /*
    For solvein this we use approach of recurssion 

       frst we make a map that store the all character with rspect to there number

       after that we call a recusrive funstio and append all the char with the particuar va;ue 


 
 */

  vector<string> helper(string& digits, int i, map<int, string>& mp){
       if(i == digits.size()) return {""};
         
          vector<string> temp;
          temp = helper(digits,i+1,mp);

             vector<string> ans;

             for(auto ele : mp[digits[i]-'0']){
                for( auto x : temp){
                      ans.push_back(ele+x);
                }
             }
             return ans;

  }
    vector<string> letterCombinations(string digits) {
              
              if (digits.empty()) return {};
               map<int,string> mp;
                mp[2] = "abc";
                mp[3] = "def";
                mp[4] = "ghi";
                mp[5] = "jkl";
                mp[6] = "mno";
                mp[7] = "pqrs";
                mp[8] = "tuv";
                mp[9] = "wxyz";
                  
                  return helper(digits,0,mp);

    }
};
