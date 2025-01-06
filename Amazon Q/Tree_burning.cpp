class Solution {
public:
  TreeNode* first = NULL;
void markParent(TreeNode* root, unordered_map<TreeNode*,TreeNode*>& parent){
        if(root==NULL) return;
        if(root->left!=NULL)  parent[root->left]=root;
        if(root->right!=NULL) parent[root->right]=root;
        markParent(root->left,parent);
        markParent(root->right,parent);
}
    void find(TreeNode* root,int start){
          if(root==NULL) return;
          if(root->val==start) {
            first = root;
            return;
          }
          find(root->left,start);
          find(root->right,start);
          
    }
    int amountOfTime(TreeNode* root, int start) {
        find(root,start);
        unordered_map<TreeNode*,TreeNode*> parent;
        unordered_set<TreeNode*> infected;
        markParent(root,parent);
        infected.insert(first);
        queue<pair<TreeNode*,int>> q;
        // pair<TreeNode*,int> p;
        // p.first = first;
        // p.second = 0;
        q.push({first,0});
        // BFS
        int maxLevel=0;
        while(q.size()>0){
            pair<TreeNode*,int> p = q.front();
            q.pop();
            int level = p.second;
            maxLevel = max(maxLevel,level);
            TreeNode* temp = p.first;
            if(temp->left!=NULL){
                if(infected.find(temp->left)==infected.end()){
                    q.push({temp->left,level+1});
                    infected.insert(temp->left);
                }

            }
             if(temp->right!=NULL){
                if(infected.find(temp->right)==infected.end()){
                    q.push({temp->right,level+1});
                    infected.insert(temp->right);
                }

            }
            if(parent.find(temp)!=parent.end()){
                 if(infected.find(parent[temp])==infected.end()){
                    q.push({parent[temp],level+1});
                    infected.insert(parent[temp]);
                }
            }
        }
        return maxLevel;
    }
};
