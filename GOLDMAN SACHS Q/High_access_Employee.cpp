class Solution {
public:
  // Approach 
  /*
     for solution we have to first check how many employee goggedin there system atlest 3 times 
         
         so for solution we make a map of string and vector that store the employee name and there time of loggedin
             
             and then we sort the value of vector
              and iterate start from 0 index and compare it woth 2nd index if thee diffrence is below 100 then we add them in answer(employee) and at last we return the string answer 
    
  */
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
            
                 // name -> access_time
                     
                      unordered_map<string, vector<int>> mp;
                        
                          for(auto &ele : access_times){
                               int time  = stoi(ele[1]);
                                mp[ele[0]].push_back(time); //  store in map
                          }

                          // now sort the vector of time;

                          for(auto &ele : mp){
                             sort(ele.second.begin(),ele.second.end());
                          }

                          // now check there timr diifernce is within 100

                               vector<string> ans;
                                
                                for(auto &ele : mp){
                                        vector<int>& time = ele.second;

                                        for(int i=2;i<time.size();i++){
                                             if(time[i]-time[i-2]<100){
                                                 //store that value in string vector

                                                 ans.push_back(ele.first);
                                                  break;

                                             }
                                        }
                                }
                                   return ans;

    }
};
