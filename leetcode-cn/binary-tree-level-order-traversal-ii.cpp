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
    std::vector<std::vector<int>> ord_per_dep;

    void dfs(int depth, TreeNode *root){
        if(root == nullptr) return;
        while(ord_per_dep.size() <= depth){
            ord_per_dep.push_back({});
        }
        ord_per_dep[depth].push_back(root->val);
        dfs(depth + 1, root->left);
        dfs(depth + 1, root->right);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        dfs(0, root);
        std::reverse(ord_per_dep.begin(), ord_per_dep.end());
        return ord_per_dep;
    }
};