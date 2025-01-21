class ThroneInheritance {
public:
     unordered_map<string, int> mp_a;
     unordered_map<int, string> mp_b;
      vector<int> arr[100005];
       int total =0;
       int dead[100005];
    ThroneInheritance(string kingName) {
           total++;
           mp_a[kingName]=total;
           mp_b[total]=kingName;
    }
    
    void birth(string parentName, string childName) {
          total++;
          mp_a[childName]=total;
          mp_b[total]=childName;
          arr[mp_a[parentName]].push_back(mp_a[childName]);
    }
    
    void death(string name) {
         dead[mp_a[name]]=1;
    }

      vector<string> ans;
       void dfs(int u){ 
          if(dead[u]==0)
             ans.push_back(mp_b[u]);
             for(int i =0;i<arr[u].size();i++){
                  dfs(arr[u][i]);
             
          }
       }
    
    vector<string> getInheritanceOrder() {
            ans.clear();
            dfs(1);
            return ans;

    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
