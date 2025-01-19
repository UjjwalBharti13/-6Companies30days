class WordDictionary {
public:
      // Approach we can solve this with the help of making map 
    // we make map of size and vector of string 
    //  then in addword we just find the word and is yes then we push that in map
    // for search Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.

     unordered_map<size_t,vector<string>> mp;
    WordDictionary() {
        
    }
     
    void addWord(string word) {
         if(mp.find(word.size())==mp.end()){
            mp[word.size()] = vector<string>();
         }   
         mp[word.size()].push_back(word);
    }
    
    bool search(string word) {
         if(mp.find(word.size())==mp.end()){
             return false;
         }
         for( auto &stored_val : mp[word.size()]){
             bool is_word_match=true;

             for(int i=0;i<word.size();i++){
                 if(word[i]=='.') continue;

                 if(stored_val[i]!=word[i]){
                     is_word_match=false;
                      break;
                 }
             }
                 if(is_word_match) return true;
         }
             return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
