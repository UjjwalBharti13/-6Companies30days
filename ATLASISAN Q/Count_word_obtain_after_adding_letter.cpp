class Solution {
public:
  // Approach 
  // for finding start string in target string we can do it revrsely
  // first all we have to sort both the vector of string 
  // and after simply we take one string form target string and remove each word one by one and check is this lying in start string
  // if they sre ltying then we can increase our count

  
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
          // making set for stroring string
           
           unordered_set<string> st;
             
             for(int i=0;i<startWords.size();i++){
                  // sorting the string array
                sort(startWords[i].begin(),startWords[i].end());
                 st.insert(startWords[i]);
                 }
              

             int count=0;
               for(int i=0;i<targetWords.size();i++){
                    string check = targetWords[i];
                    sort(check.begin(),check.end());

                    bool found = false;
                     for(int i=0;i<check.size();i++){
                         string search = check.substr(0,i)+check.substr(i+1);
                         if(st.find(search)!=st.end()){
                              found = true;
                               break;
                         }
                     }
                       if(found) count++;
               }
                 return count;
    }
};
