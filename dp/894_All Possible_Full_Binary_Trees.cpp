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
    vector<TreeNode*> solve(int n)
    {
        if(n%2==0)
        {
            return {};
        }
        if(n==1)
        {
            TreeNode * root= new TreeNode(0);
            return {root};
        }
        vector<TreeNode*> result;
        for(int i=1;i<n;i+=2)
        {
        vector<TreeNode*> leftallFBT= solve(i);
        vector<TreeNode*>  rightallFBT= solve(n-i-1);
        for(auto&l :leftallFBT)
        {
            for(auto&r :rightallFBT)
            {
                TreeNode* root= new TreeNode(0);
                root->left=l;
                root->right=r;
                result.push_back(root);
            }
        }
        }
        return result;

    }

    vector<TreeNode*> allPossibleFBT(int n) {
        return solve(n);
    }
};
//MEOIZATION
class Solution {
public:
unordered_map<int,vector<TreeNode*>>mp;
    vector<TreeNode*> solve(int n)
    {
        if(n%2==0)
        {
            return {};
        }
        if(n==1)
        {
            TreeNode * root= new TreeNode(0);
            return {root};
        }
        if(mp.find(n)!=mp.end())return mp[n];
        vector<TreeNode*> result;
        for(int i=1;i<n;i+=2)
        {
        vector<TreeNode*> leftallFBT= solve(i);
        vector<TreeNode*>  rightallFBT= solve(n-i-1);
        for(auto&l :leftallFBT)
        {
            for(auto&r :rightallFBT)
            {
                TreeNode* root= new TreeNode(0);
                root->left=l;
                root->right=r;
                result.push_back(root);
            }
        }
        }
        return mp[n]=result;

    }

    vector<TreeNode*> allPossibleFBT(int n) {
        return solve(n);
    }
};