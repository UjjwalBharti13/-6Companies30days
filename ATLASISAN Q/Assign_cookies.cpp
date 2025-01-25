class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n= g.size();
        int m = s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int count = 0;
        int i=0;
        int j=0;
        while(i<g.size() && j<s.size()){
            if(s[j]>=g[i]){count++;
            i++;
            j++;
            }else j++;
        
        }
    return count;
    }
};