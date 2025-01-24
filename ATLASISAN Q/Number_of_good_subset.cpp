class Solution {
public:
 // Approach
  //  given consytrains is below 30 so first i have to take all prime number upto 30 and representing with index value in vector
   // now we implement the basic prime factorization part of each element 
  // now we use bit mask to maintain the subset value index with 0101 type 
  // handle of corener case like 
  /* if we gor good subset like more frequency of each number like 
      6 6 5 5 5 4 4
     then we can return the value of freq[6]*freq[5]*freq[4]
         
          now one handle one more cases like we we got value of multiple 1
           1 1 1
              then we can take value of 
              3c1 + 3c2 + 3c3 = 2^3-1  // this is formula 

              now we do recurssion like either we can skip the elemnet 
              id we are going to take the element then we have to check the value of element in mask either it is taken or not if not then we oush the value in vector 
                 
                 and after that count the total value of 1 in vector then return with the formula of 2^c-1

                 Below is Implementation 

  */

    #define ll long long int 
    ll mod = 1000000007;
    ll dp[40][2500];

    ll helper(int curr, int mask, vector<int>& elem, map<int,int>& no_prime_mask, vector<int>& arr, map<int,int>& freq){
                   
                     if(curr>=elem.size()){
                        ll count =1;
                          
                          for(auto ele : arr){
                              count  = (count%mod * freq[ele]%mod)%mod;
                          }

                               return count;
                     }

                     ll ans= helper(curr+1,mask,elem,no_prime_mask,arr,freq);
                     // checking the elemment in mask 

                      if((no_prime_mask[elem[curr]]&mask)==0){
                         arr.push_back(elem[curr]);
                           ans = (ans%mod + helper(curr+1,mask^no_prime_mask[elem[curr]],elem,no_prime_mask,arr,freq)%mod)%mod;
                              arr.pop_back();
                      }
                        return ans;

    }
     

    int numberOfGoodSubsets(vector<int>& nums) {
            vector<int> primes = {2,3,5,7,11,13,17,19,23,29};
              int n = primes.size();
                 
                   map<int,int> mpIdx; 
                      for(int i=0;i<n;i++){
                           mpIdx[primes[i]]=i;
                      }

                        map<int,int> no_prime_mask;
                        int no_one =0;
                          
                          // doing for uniques lement 

                           set<int> st_elmn;
                              map<int,int> freq;

                                for( auto ele : nums){
                                     if(ele==1){
                                         no_one++;
                                         continue;
                                     }
                                     bool flag= true;

                                        int primeMask =0;

                                        int curr = ele;

                                        for(int j=2;j*j<=ele;j++){
                                               int count =0 ;

                                               while(curr%j==0){
                                                    curr = curr/j;
                                                    count++;
                                               }
                                               // checking the value of mask
                                                if(count>0 and count!=1){
                                                    flag  = false;
                                                }
                                                else if(count==1){
                                                     primeMask = primeMask ^ (1<<mpIdx[j]);
                                                }
                                        } 
                                        if(curr!=1){
                                             primeMask = primeMask^(1<<mpIdx[curr]);
                                        }
                                        if(flag){
                                              st_elmn.insert(ele);
                                              freq[ele]++;
                                              no_prime_mask[ele] = primeMask;
                                                
                                        }
                                }
                                          
                                          vector<int> arr;
                                            
                                             vector<int> unique(st_elmn.begin(), st_elmn.end());

                                                memset( dp ,-1, sizeof dp);

                                                ll ans=  helper(0,0,unique,no_prime_mask,arr,freq);
                                                  
                                                   ans = (ans-1+mod)%mod; // for empty set taking -1

                                                     ll total_one=1;
                                                     for(int i=1;i<=no_one;i++){
                                                         total_one = (total_one%mod * 2%mod)%mod;
                                                     }
                                                       // handle one
                                                        ans= (ans%mod + ((total_one-1+mod)%mod * ans%mod)%mod)%mod;
                                                          return ans;
                                                          
                                
                                 

    }
};
