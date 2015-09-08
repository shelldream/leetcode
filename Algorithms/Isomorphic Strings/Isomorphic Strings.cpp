/**
	Isomorphic Strings
	Author:Xiaojun Huang
	Date:2015-09-08

*/

#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> my_map;
        map<char,int> already_map;
        int m = s.size();
        int n = t.size();
        if(m != n)
            return false;
        for(int i = 0;i < m;i++)
        {
            if(my_map.count(s[i]) == 0)
            {
                my_map[s[i]] = t[i];
                if(already_map.count(t[i]) == 1)
                    return false;
                already_map[t[i]] = 1;
            }
            else
            {
                if(my_map[s[i]] != t[i])
                    return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution test;
    cout<<test.isIsomorphic("abcc", "ABCC")<<endl;
    cout<<test.isIsomorphic("abcc", "ABCD")<<endl;
    cout<<test.isIsomorphic("abcc", "AACD")<<endl;
}
