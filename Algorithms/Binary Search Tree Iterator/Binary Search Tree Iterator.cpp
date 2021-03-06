/*
	Binary Search Tree Iterator
	Author:Xiaojun Huang
	Date:2015-08-06

*/

#include <iostream>
#include <vector>
#include <stack>
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



class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        TreeNode* tmp = root;
        while(tmp)
        {
            path.push(tmp);
            tmp = tmp->left;
        }
    }
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !path.empty();
    }
    /** @return the next smallest number */
    int next() {
        return get_min();
    }
    int get_min()
    {
        TreeNode* root = path.top();
        int ans = root->val;
        path.pop();
        if(root->right)
        {
            TreeNode* tmp = root->right;
            while(tmp)
            {
                path.push(tmp);
                tmp = tmp->left;
            }
        }
        return ans;
    }
private:
    TreeNode* current_node;
    stack<TreeNode*> path;
};

int main()
{
    int data1[] = {5,3,2,1,4,8,7,6,9,10};
    int data2[] = {1,2,3,4,5,6,7,8,9,10};
    int n1 = sizeof(data1)/sizeof(data1[0]);
    int n2 = sizeof(data2)/sizeof(data2[0]);
    vector<int> preorder(data1,data1+n1);
    vector<int> inorder(data2, data2+n2);
    TreeNode* root = buildTree(preorder,inorder);
    BSTIterator i = BSTIterator(root);
    while(i.hasNext())
        cout<<i.next()<<endl;
}
