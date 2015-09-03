/**
	Length of Last Word
	Author:Xiaojun Huang
	Date:2015-09-03

*/

#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        int i = s.size()-1;
        while(i >= 0 && s[i] == ' ')
            i--;
        while(i >= 0 && s[i] != ' ')
        {
            ans++;
            i--;
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    cout<<solution.lengthOfLastWord("asfdsafd dsfsdfd dsfds")<<endl;
    cout<<solution.lengthOfLastWord("sdfdsfds abcdef     ")<<endl;
    cout<<solution.lengthOfLastWord("               ")<<endl;
}
