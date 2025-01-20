/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
 //Approach  
 // we solve it with traversin each node from leaf side
 // we do dfs from leaf side and then going upperside one by ony by incrementing ans 
 // if dist is still smaller than we push the value in vector otherwise return answer at the end 

int ans=0; // making global var
 vector<int> helper(TreeNode* root, int dist){
       if(!root) return {};
    if(!root->left and !root->right) return {1};

        auto left_side = helper(root->left,dist);
        auto right_side = helper(root->right,dist);

           for(auto a : left_side){
             for(auto b : right_side){
                 if(a+b<=dist) ans++;
             }
           }

           vector<int> arr;
            for(auto a : left_side){
                 if(a+1<dist) arr.push_back(a+1);
            }
              for(auto b : right_side){
                 if(b+1<dist) arr.push_back(b+1);
            }
             return arr;

 }
    int countPairs(TreeNode* root, int dist) {
          helper(root,dist);
           return ans;
    }
};
