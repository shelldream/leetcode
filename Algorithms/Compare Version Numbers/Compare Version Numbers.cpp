/**
	Compare Version Numbers
	Author:Xiaojun Huang
	Date:2015-09-09

*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int str2int(string s)
    {
        int ans = 0;
        if(s == "")
            return 0;
        for(int i = 0;i < s.size();i++)
        {
            ans = ans*10 + s[i] - '0';
        }
        return ans;
    }
    int get_version_number(string s, int &v)
    {
        int i = 0;
        if(s.size() == 0)
            return 0;
        while(s[i] != '.' && i < s.size())
            i++;
        v = str2int(s.substr(0,i));
        return i;
    }
    int compareVersion(string version1, string version2) {
        int v1 = 0;
        int dot1 = get_version_number(version1, v1);
        int v2 = 0;
        int dot2 = get_version_number(version2, v2);

        if(v1 > v2)
            return 1;
        else if(v1 < v2)
            return -1;
        else
        {
            string s1 = "";
            if(dot1 < version1.size()-1 && version1 != "")
                s1 = version1.substr(dot1+1, version1.size()-1-dot1);
            string s2 = "";
            if(dot2 < version2.size()-1 && version2 != "")
                s2 = version2.substr(dot2+1, version2.size()-1-dot2);
            if(s1 == "" && s2 == "")
                return 0;
            return compareVersion(s1,s2);
        }
    }
};

int main()
{
    Solution test;
    string s1 = "1.0.000.4";
    string s2 = "1.1.0";
    //string s1 = "19.8.3.17.5.01.0.0.4.0.0.0.0.0.0.0.0.0.0.0.0.0.00.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000";
    //string s2 = "19.8.3.17.5.01.0.0.4.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0000.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000";
    cout<<test.compareVersion(s1,s2)<<endl;

}
