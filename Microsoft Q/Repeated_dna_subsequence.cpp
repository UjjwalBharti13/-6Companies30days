class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        if(s.length()<10)
            return ans;
        unordered_map<string,int> m;
        for(int i=0;i<s.length()-9;i++)
        {
            string s1 = s.substr(i,10);
            m[s1]++;
            if(m[s1]>1 && count(ans.begin(),ans.end(),s1)==0)
                ans.push_back(s1);
        }
        return ans;
    }
};
