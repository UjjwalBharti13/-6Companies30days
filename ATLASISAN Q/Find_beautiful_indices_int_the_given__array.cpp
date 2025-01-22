class Solution {
public:
 // Approach
 // we can check every substring which make value with the inbuild funtion
 // and then we iterate all x and y and check the absolute val of i-j <=k then pusgh thay val in arr

  void findIndex(string str, string a, vector<int>& arr){
     auto pos = str.find(a,0);
         if(pos==string::npos)return ;

          while(pos!=string::npos){
              arr.push_back(pos);
               pos=str.find(a,pos+1);
          } 
             return;
  }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
            
            vector<int>x, y;
             findIndex(s,a,x);
             findIndex(s,b,y);
                 
                     vector<int> ans;
                      for( auto i : x){
                         for(auto j : y){
                             if(abs(i-j)<=k){
                                 ans.push_back(i);
                                  break;
                             }
                         }
                      }
                       return ans;

    }

};
