class Solution {
public:
  // Approach 
   //  the approach is simple we have to hanle for three char case like 
    /*
          if we got R and L continuous then add 2 as point and 
          in other case like if collide with stable ans ans = 1

          intutuions is clear first we count all the frequency of each char 
          then we iterrate the vector and check the contigous char if they are R and L then add the val 2 add of that freq 
          otherwise 1

   
   
   */
    int countCollisions(string str) {
          
            vector<pair<char,int>> arr;
              
               for(int i=0;i<str.size();i++){
                     
                     int count =1;
                        while(i+1< str.size() and str[i]==str[i+1]){
                            i++;
                            count++;
                        }
                         arr.push_back({str[i],count});
               }
                  int ans=0;
                     for(int i=0;i<arr.size()-1;i++){
                           
                            if(arr[i].first=='R' and arr[i+1].first=='L'){
                                 ans+=arr[i].second + arr[i+1].second;
                            }
                            else if(arr[i].first=='S' and arr[i+1].first=='L'){
                                   ans+=arr[i+1].second;
                            }
                              else if(arr[i].first=='R' and arr[i+1].first=='S') {
                                 ans+= arr[i].second;
                              }
                            

                     }
                         return ans;
    }
};
