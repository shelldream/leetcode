/**
	Symmetric Tree
	Author:Xiaojun Huang
	Date:2015-09-09

*/

#include <iostream>
#include <vector>
#include <queue>
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
        inorder_root_index++;
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

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return isTwoSymmetric(root->left, root->right);
    }
    bool isTwoSymmetric(TreeNode* root1, TreeNode* root2)
    {
        if(!root1 && !root2)
            return true;
        else if(root1 && root2)
        {
            if(root1->val != root2->val)
                return false;
            else
            {
                return isTwoSymmetric(root1->left, root2->right) && isTwoSymmetric(root1->right, root2->left);
            }
        }
        else return false;
    }
};

int main()
{
    //int data1[] = {5,3,2,1,4,8,7,6,9,10};
    //int data2[] = {1,2,3,4,5,6,7,8,9,10};
    int data1[] = {1,2,3,4,2,4,3};
    int data2[] = {3,2,4,1,4,2,3};
    int n1 = sizeof(data1)/sizeof(data1[0]);
    int n2 = sizeof(data2)/sizeof(data2[0]);
    vector<int> preorder(data1,data1+n1);
    vector<int> inorder(data2, data2+n2);
    TreeNode* root = buildTree(preorder,inorder);
    Solution test;
    cout<<test.isSymmetric(root)<<endl;
}

