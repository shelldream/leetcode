/**
	Binary Tree Paths
	Author:Xiaojun Huang
	Date:2015-09-03

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

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        vector<int> path;
        PreorderTraverse(root, path, ans);
        return ans;
    }
    string int2str(int i)
    {
        if(i == 0)
            return "0";
        bool isNegative = false;
        if(i < 0)
        {
            isNegative = true;
            i = -i;
        }
        string ans = "";
        while(i)
        {
            char tmp = i%10 + '0';
            ans = tmp + ans;
            i /= 10;
        }
        if(isNegative)
            return "-" + ans;
        else return ans;
    }
    void PreorderTraverse(TreeNode* root, vector<int>& path, vector<string>& ans)
    {
       if(root)
       {
           path.push_back(root->val);
           if(root->left == NULL && root->right == NULL)
           {

               string tmp = "";
               for(int i = 0;i < path.size(); i++)
               {
                   if(i != path.size()-1)
                    {
                        tmp += int2str(path[i]);
                        tmp += "->";
                    }
                   else tmp += int2str(path[i]);

               }
               ans.push_back(tmp);
           }
           else
           {
               if(root->left)
               {
                   PreorderTraverse(root->left, path, ans);
               }
               if(root->right)
               {
                   PreorderTraverse(root->right, path, ans);
               }
           }
           path.pop_back();
       }
    }
};



int main()
{
    int data1[] = {-100,2,500,3};
    int data2[] = {2,500,-100,3};
    int n1 = sizeof(data1)/sizeof(data1[0]);
    int n2 = sizeof(data2)/sizeof(data2[0]);
    vector<int> preorder(data1,data1+n1);
    vector<int> inorder(data2, data2+n2);
    TreeNode* root = buildTree(preorder,inorder);
    Solution solution;
    vector<string> ans = solution.binaryTreePaths(root);
    for(int i = 0;i < ans.size();i++)
        cout<<ans[i]<<"  ";
    cout<<endl;
}
