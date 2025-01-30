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
  
  // Approach  
  /*
      for solving this we use the aproach like we have to find sum of BST and check weather it is valid
      BST or not  
         
          for edge case we return min val as left subtree and max as rightsubtree
              
                if we find that the root is not valis BST then we return the max vakue of left BST sum and right BST
                Sum

                  we maintain 3 size array that store the value of min value max valur and sum of the Tree    
            
            for finding sum or it is valid BST or not we do postorder traversal 
  
    
   
  */


class Solution {
public:
   vector<int>  dfs(TreeNode* root,int& ans){
         // base case
            if(root==NULL) {
                  return {INT_MAX, INT_MIN,0};

            }
               
               vector<int> leftSubtree = dfs(root->left,ans); 
               vector<int> rightSubtree = dfs(root->right,ans); 

               // check if currect  subtree is BST
                 
                 if(root->val>leftSubtree[1] and root->val < rightSubtree[0]){
                        int currSum = leftSubtree[2] + rightSubtree[2]+root->val;
                            ans  = max(ans,currSum);
                            int minVal = min(root->val,leftSubtree[0]);
                            int maxVal = max(root->val,rightSubtree[1]);
                               
                               return {minVal,maxVal,currSum};
                 }
                     
                     int mxSum = max(leftSubtree[2],rightSubtree[2]);
                 return {INT_MIN,INT_MAX,mxSum};
                    
   }
    int maxSumBST(TreeNode* root) {
             int ans =0;
               dfs(root,ans);
                  return ans;

               
    }
};
