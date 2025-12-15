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
//     bool isSameTree(TreeNode* p, TreeNode* q) {
//         if(!p && !q){
//             return true;
//         }
//         if(p && q) {
//             return (p ->val == q ->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//         }
//         return false;
//     }
 bool isSameTree(TreeNode* p, TreeNode* q) {
    queue<pair<TreeNode*,TreeNode*>>qu;
    qu.push({p,q});
    while(!qu.empty()) {
        auto node = qu.front();
        qu.pop();

        TreeNode* n1 = node.first;
        TreeNode* n2 = node.second;

        if(n1 == NULL & n2 == NULL)
        continue;
        if(n1 == NULL || n2 == NULL || n1->val != n2->val)
        return false;

        qu.push({n1->left,n2->left});
        qu.push({n1->right,n2->right});
    }
    return true;
 }
};