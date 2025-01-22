class Solution {
public: 
//Approach
 // we can make all bonary represattion of the given number 
 // for minmising the miltiplication we can take half of value at lowest like 0 in front and half of val o at end
 // one binary is full of bitset 
 // we multiply all the value then we get answer 

   #define ll long long int 
  ll mod = 1e9+7;
     
     ll MOD(ll x){
         return (x%mod+mod)%mod;
     }
     
     ll mult(ll a, ll b){
         return MOD(MOD(a)*MOD(b));
     }
     ll modPow(ll a, ll b){
         if(b==0) return 1LL;
         if(b==1) return a;
           
             ll res =1;
             while(b){
                 if(b%2==1) res = mult(res,a);
                   b/=2;
                   a = mult(a,a);
             }
                return res;
                 
     }

    int minNonZeroProduct(int p) {
          ll largest =0;
            for(int i=0;i<p;i++){
                  largest+=(1LL<<i);
            }
               ll ans = mult(largest,modPow(largest-1,largest/2));
                   return ans;

    }
};
