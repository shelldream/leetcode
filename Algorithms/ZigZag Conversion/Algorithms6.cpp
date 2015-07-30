/*
	Longest Substring Without Repeating Characters
	Author:Xiaojun Huang
	Date:2015-6-30
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        int s_len = s.length();
        string ans="";
        vector<string> outputs;
        for(int i = 0;i<numRows;i++)
            outputs.push_back("");
        int j = 0;
        int k = 0;
        bool down_flag = true;
        while(j < s_len)
        {
            outputs[k] += s[j];
            j++;
            if(k < numRows-1 && k > 0)
            {
                if(down_flag)
                    k++;
                else
                    k--;
            }
            else if(k== numRows-1)
            {
                k--;
                down_flag = false;
            }
            else if(k == 0)
            {
                k++;
                down_flag = true;
            }
        }
        for(int i = 0;i<numRows;i++)
            ans += outputs[i];
        return ans;
    }
};


int main()
{
    string test = "PAYPALISHIRING";
    Solution solution;
    cout<<solution.convert(test,3)<<endl;
}
