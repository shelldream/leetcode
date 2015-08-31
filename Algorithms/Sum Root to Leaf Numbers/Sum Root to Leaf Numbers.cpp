/*
	Sum Root to Leaf Numbers
	Author:Xiaojun Huang
	Date:2015-08-31

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
        inorder_root_index++; //���Ҹ��ڵ��ں��������е��±�
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
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        vector<int> path;
        PreOrderTraverse(root,path,ans);
        return ans;
    }
    void PreOrderTraverse(TreeNode* root, vector<int>& path, int& sum)
    {
        if(root)
        {
            path.push_back(root->val);
            if(!root->left && !root->right)
            {
                int tmp = 0;
                for(int i = 0;i < path.size();i++)
                {
                    tmp = tmp*10 + path[i];
                }
                sum += tmp;
            }
            else
            {
                PreOrderTraverse(root->left,path,sum);
                PreOrderTraverse(root->right,path,sum);
            }
            path.pop_back();
        }
    }
};

int main()
{
    int data1[] = {1,2,4,5,6,3};
    int data2[] = {4,5,2,6,1,3};
    int n1 = sizeof(data1)/sizeof(data1[0]);
    int n2 = sizeof(data2)/sizeof(data2[0]);
    vector<int> preorder(data1,data1+n1);
    vector<int> inorder(data2, data2+n2);
    TreeNode* root = buildTree(preorder,inorder);
    Solution solution;
    cout<<solution.sumNumbers(root)<<endl;
}
