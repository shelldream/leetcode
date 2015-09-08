/**
	Same Tree
	Author:Xiaojun Huang
	Date:2015-09-08

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)
            return true;
        else if(p && q)
        {
            if(p->val != q->val)
                return false;
            else
            {
                return isSameTree(p->left,q->left) && isSameTree(p->right, q->right);
            }
        }
        else return false;
    }
};

int main()
{
    int data1[] = {5,3,2,1,4,8,7,6,9,10};
    int data2[] = {1,2,3,4,5,6,7,8,9,10};
    int data3[] = {5,3,2,1,4,8,7,6,9,11};
    int data4[] = {1,2,3,4,5,6,7,8,9,11};
    int n1 = sizeof(data1)/sizeof(data1[0]);
    int n2 = sizeof(data2)/sizeof(data2[0]);
    int n3 = sizeof(data3)/sizeof(data3[0]);
    int n4 = sizeof(data4)/sizeof(data4[0]);
    vector<int> preorder1(data1,data1+n1);
    vector<int> preorder2(data3,data3+n1);
    vector<int> inorder1(data2, data2+n2);
    vector<int> inorder2(data4, data4+n4);
    TreeNode* root1 = buildTree(preorder1,inorder1);
    TreeNode* root2 = buildTree(preorder1,inorder1);
    TreeNode* root3 = buildTree(preorder2,inorder2);
    Solution test;
    cout<<test.isSameTree(root1,root2)<<endl;
    cout<<test.isSameTree(root1,root3)<<endl;
}

