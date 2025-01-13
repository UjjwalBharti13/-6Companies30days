class Solution {
public:
             /* take realtion from two equation 
                  
                  like  if -;
                   give 5 length of array is
                    [a,b,c,d,e]  n=5;
                     from given situation we can make eq like 
                  f(0) = (0*a)+(1*b)+(2*c)+(3*d)+(4*e);
                  f(1) = (1*a)+(2*b)+(3*c)+(4*d)+(0*e);
                  f(2) = (2*a)+(3*b)+(4*c)+(0*d)+(1*e);

                  we can make new realtion by subtracting twoo eq 

                  if we did f(1)-f(0) = a+b+c+d+e-5e
                    therefore, 
                    f(1)=f(0)+sum-5e= f(0)-n*e

                    now do with f(2)-f(1) = a+b+c+d+e-5d
                     therefor,
                      f(2) = f(1)+sum-5d = f(1)-n*d

                      after generlise we make eq like

                      f(k) = f(k-1) + sum - n*(k-1)th element from the array
                        therefor simple eq be 
                         f(k) = f(k-1) + sum  - n*(arr[n-1-(k-1)]) = f(k-1) + sum - n*(arr[n-k])
                          
          */   

     int helper(vector<int>& nums, int n, int sum, int currF, int k){
             if(k == 0) return currF;
               currF = currF+sum-n*nums[(n-k)%n];
            return max(currF,helper(nums,n,sum,currF,k-1));
           
     }
    int maxRotateFunction(vector<int>& nums) {
              int n= nums.size();
                 int sum =0;
                  int fo = 0;
              for(int i=0;i<n;i++){
                     sum += nums[i];
                      fo+= i*nums[i];
                 }  
        // return helper(nums,n,sum,fo,n-1);   
             int maxVal = fo;
             int curr=fo;
               for(int k=1;k<n;k++){
                 curr = curr+sum-n*nums[n-k];
                  maxVal = max(maxVal,curr);
               }       
                 return maxVal;
                 
    }
};
