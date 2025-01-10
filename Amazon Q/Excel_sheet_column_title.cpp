class Solution {
public:
    string convertToTitle(int num) {
          string s = "";
          while(num){
             num-=1;
             char ch = 'A' +num%26;
               s+=ch;
               num/=26;
          }
             reverse(s.begin(),s.end());
              return s;
    }
};
