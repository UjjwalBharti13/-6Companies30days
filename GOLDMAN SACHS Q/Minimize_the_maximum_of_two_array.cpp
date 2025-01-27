class Solution {
public:
 // Approach 
 // Due to high constrains simply we can use Binary Search to get answer
 /* 
      we handle the case if there are a number wgich is not divisibe in d1 and b number which 
      is not divisible by d2 and there are c number which are not divisible d1 and d2 so
         check a >= unq1
               b>=unq2
               a+b-c >= unq1+unq2;

               we do binary search anf if thse
                 but we have to add multiple occurance with the help of gcd

                 
     
 
 */
 
 #define ll long long int
    
     ll gcd(ll a, ll b){
         if(a%b==0) return b;
         else return gcd(b,a%b);
     }

    ll minimizeSet(ll divisor1, ll divisor2, ll uniqueCnt1, ll uniqueCnt2) {
        
           // binary Search

           ll left=2;
           ll right=10000000000;
           ll ans= 10000000000;
             
            ll lcm = (divisor1*divisor2)/gcd(divisor1,divisor2);

            while(left<=right){
                  ll mid = (left+(right-left)/2);


                  ll countA = mid-(mid/divisor1); // element not divisible by divisor1
                  ll countB = mid-(mid/divisor2); //  element not divisible by divisor2
                  ll countCommon = mid-(mid/divisor1)-(mid/divisor2)+(mid/lcm); // common elemnt 

                  if(countA>=uniqueCnt1 and countB>= uniqueCnt2 and countA+countB-countCommon>=uniqueCnt1+uniqueCnt2){
                          ans=mid;

                           right = mid-1;
                  }
                  else { 
                     left= mid+1;  
                  }
            }
               return ans;

           
    }
};
