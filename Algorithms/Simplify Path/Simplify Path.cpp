/**
	Simplify Path
	Author:Xiaojun Huang
	Date:2015-08-06
*/

#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        int i = 0;
        string ans = "";
        stack<string> dir_stack;
        while(i < path.size())
        {
            int j = i+1;
            while(j < path.size() && path[j] != '/')
                j++;
            if(j-i-1)
            {
                string tmp = path.substr(i+1,j-i-1);
                if(tmp != "." && tmp != "..")
                    dir_stack.push(tmp);
                else if(tmp == "..")
                {
                    if(!dir_stack.empty())
                        dir_stack.pop();
                }
            }
            i = j;
        }
        vector<string> dir_vector;
        while(!dir_stack.empty())
        {
            dir_vector.push_back(dir_stack.top());
            dir_stack.pop();
        }
        for(int i = dir_vector.size()-1;i >= 0;i--)
        {
            ans += "/";
            ans += dir_vector[i];
        }
        if(ans == "")
            return "/";
        else return ans;
    }
};

int main()
{
	//string test = "/a/./b/../../c/";
	//string test = "/home//foo/";
	string test = "/../../../../";
	Solution solution;
	cout<<solution.simplifyPath(test);
}
