/*
	Valid Parentheses
	Author:Xiaojun Huang
	Date:2015-07-23

*/

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> char_stack;
        for(int i=0;i<n;i++)
        {
            char current = s[i];
            if(current == ']')
            {
                if(char_stack.empty())
                    return false;
                char top = char_stack.top();
                if(top != '[')
                    return false;
                else
                    char_stack.pop();
            }
            else if(current == ')')
            {
                if(char_stack.empty())
                    return false;
                char top = char_stack.top();
                if(top != '(')
                    return false;
                else
                    char_stack.pop();
            }
            else if(current == '}')
            {
                if(char_stack.empty())
                    return false;
                char top = char_stack.top();
                if(top != '{')
                    return false;
                else
                    char_stack.pop();
            }
            else
            {
                char_stack.push(current);
            }
        }
        if(!char_stack.empty())
            return false;
        return true;
    }
};

int main()
{
    //string test = "{[}[";
    string test = "]";
    Solution solution;
    cout<<solution.isValid(test)<<endl;
}

/*
หตร๗


*/
