class Solution {
public:
    string frequencySort(string s) {
        vector<int> freq(128,0);
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            int ascii = (int)ch;
            freq[ascii]++;
        }

        vector<pair<int,char>> v;
        for(int i=0;i<freq.size();i++){
            char ch = (char)i;
            if(freq[i]>0){
                v.push_back({freq[i],ch});
            }
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        string ans ="";
        for(int i=0;i<v.size();i++){
            pair p = v[i];
            int f = p.first;
            char ch = p.second;
           for(int j=1;j<=f;j++){
            ans.push_back(ch);
           }
        }
        return ans;
    }
};
