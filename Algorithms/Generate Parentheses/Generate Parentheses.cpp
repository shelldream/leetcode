/*
	Generate Parentheses
	Author:Xiaojun Huang
	Date:2015-07-23

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> ans;
    void generate_func(string s, int l_left, int r_left)
    {
        if(r_left < l_left)
            return;
        if(l_left == 0 && r_left == 0)
            ans.push_back(s);
        if(l_left != 0)
            generate_func(s+'(',l_left-1,r_left);
        if(r_left != 0)
            generate_func(s+')',l_left,r_left-1);

    }
    vector<string> generateParenthesis(int n) {
        string s = "";
        generate_func(s,n,n);
        return ans;
    }
};

int main()
{
    Solution solution;
    vector<string> ans = solution.generateParenthesis(3);
    for(int i = 0;i<ans.size();i++)
        cout<<ans[i]<<endl;
}

/*หตร๗


*/
