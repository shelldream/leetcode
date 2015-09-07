/**
	Lowest Common Ancestor of a Binary Search Tree
	Author:Xiaojun Huang
	Date:2015-09-07

*/

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* buildFunc(vector<int>& preorder, int i, int j, vector<int>& inorder, int x, int y)
{
    if(i > j || x > y || i<0 || j<0 || x<0 || y <0 || i>=preorder.size() || j>=preorder.size() || x>=inorder.size() || y>=inorder.size())
        return NULL;
    int root_val = preorder[i];
    TreeNode* root = new TreeNode(root_val);
    int inorder_root_index = x;
    while(inorder[inorder_root_index] != root_val)
        inorder_root_index++; //查找根节点在后序数组中的下标
    int left_tree_node_count = inorder_root_index-x;
    int right_tree_node_count = y-inorder_root_index;
    root->left = buildFunc(preorder, i+1, i+left_tree_node_count, inorder, x, x+left_tree_node_count-1);
    root->right = buildFunc(preorder, i+left_tree_node_count+1, j, inorder, inorder_root_index+1, y);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int j = preorder.size()-1;
        int y = inorder.size()-1;
        return buildFunc(preorder, 0, j, inorder, 0, y);
    }

TreeNode* get_Node(TreeNode* root, int target)
{
    if(!root)
        return NULL;
    if(root->val == target)
        return root;
    TreeNode* left_result = get_Node(root->left,target);
    TreeNode* right_result = get_Node(root->right,target);
    if(left_result)
        return left_result;
    if(right_result)
        return right_result;
    return NULL;
}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> p_path;
        vector<TreeNode*> q_path;
        Traverse(p_path, root, p->val);
        Traverse(q_path, root, q->val);
        int n = min(p_path.size(),q_path.size());
        int i = 0;
        while(i < n)
        {
            if(p_path[i]->val == q_path[i]->val)
                    i++;
            else return p_path[i-1];
        }
        return p_path[n-1];
    }
    void Traverse(vector<TreeNode*>& path, TreeNode* root, int val)
    {
        path.push_back(root);
        if(root->val > val)
        {
            Traverse(path, root->left, val);
        }
        else if(root->val < val)
        {
            Traverse(path, root->right, val);
        }
    }
};

int main()
{
    int data1[] = {6,2,0,4,3,5,8,7,9};
    int data2[] = {0,2,3,4,5,6,7,8,9};
    int n1 = sizeof(data1)/sizeof(data1[0]);
    int n2 = sizeof(data2)/sizeof(data2[0]);
    vector<int> preorder(data1,data1+n1);
    vector<int> inorder(data2, data2+n2);
    TreeNode* root = buildTree(preorder,inorder);
    TreeNode* test1 = get_Node(root,3);
    TreeNode* test2 = get_Node(root,7);
    Solution solution;
    cout<<solution.lowestCommonAncestor(root,test1,test2)->val<<endl;
}
