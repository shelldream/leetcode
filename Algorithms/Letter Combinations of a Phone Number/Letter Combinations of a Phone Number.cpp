/*
	Letter Combinations of a Phone Number
	Author:Xiaojun Huang
	Date:2015-07-27

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string digit2char[9] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        return combination(digits);
    }

    vector<string> combination(string digits)
    {
        vector<string> ans;
        if(digits.length() == 0)
            return ans;
        int j = digits[0] - '1';
        string tmp = digit2char[j];
        for(int k = 0;k < tmp.length();k++)
        {
            char current_digit2char = tmp[k];
            vector<string> rest = combination(digits.substr(1,digits.length()-1));
            if(rest.size()==0)
            {
                string tmp_str = "";
                tmp_str += current_digit2char;
                ans.push_back(tmp_str);
            }
            else
            {
                for(int m = 0;m < rest.size();m++)
                {
                    string tmp_str = "";
                    tmp_str += current_digit2char + rest[m];
                    ans.push_back(tmp_str);
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    vector<string> ans = solution.letterCombinations("234");
    for(int i = 0;i < ans.size();i++)
        cout<<ans[i]<<endl;
}
