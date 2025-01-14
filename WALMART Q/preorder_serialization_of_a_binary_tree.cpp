class Solution {
public:
    bool isValidSerialization(string preorder) {
         stringstream s(preorder);
            stack<string> st;
              string str;
                
                 while(getline(s,str,',')){
                     if(st.empty() or str!="#") {
                         st.push(str);
                     }
                     else{
                         while(!st.empty()  and st.top()=="#"){
                             st.pop();
                             if(st.empty()) return false;
                               else st.pop();
                         }
                           st.push(str);
                     }
                 }
                   return st.size()==1 and st.top()=="#";
    }
};
