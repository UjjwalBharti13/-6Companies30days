class Solution {
public:
 // Approch 
 // we can simply think if we remove consecutive line than we can get max area
 // i usually think first we calculate the max count of consecutive element that can give me largest are
 // we perform thse operation for vertically and horizontally then we got maximum area which are scapping with the help of count of consecitive element 
 // then for both side height and width we have to return square so we can take minimum from both of them then return the square of that value  
    int maximizeSquareHoleArea(int n, int m, vector<int>& num1, vector<int>& num2) {
          
            sort(num1.begin(),num1.end());
            sort(num2.begin(),num2.end());
              
               int ver_count=1;
               int max_vcount=1;
                for(int i=0;i<num1.size()-1;i++){
                        if(num1[i]+1==num1[i+1]) ver_count++;
                         else {
                            ver_count=1;
                         }
                            max_vcount= max(max_vcount,ver_count);
                         
                  }
                     
               int hor_count=1;
               int max_hcount=1;   
                      for(int i=0;i<num2.size()-1;i++){
                        if(num2[i]+1==num2[i+1]) hor_count++;
                         else {
                            hor_count=1;
                         }
                            max_hcount=max(max_hcount,hor_count);
                         
                  }
                      int ans=min(max_vcount,max_hcount)+1;
                      return ans*ans;
    }
};
