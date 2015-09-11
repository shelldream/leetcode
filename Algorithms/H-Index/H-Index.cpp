/**
	H-Index
	Author:Xiaojun Huang
	Date:2015-09-11

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int index = 0;
        for(int i = citations.size()-1;i >= 0;i--)
        {
            if(citations[i] >= index+1)
                index++;
            else break;
        }
        return index;
    }
};

int main()
{
    //int data[] = {2,1,21,12,54,323,65};
    int data[] = {0,0,0,0,0};
    int n = sizeof(data)/sizeof(data[0]);
    vector<int> nums(data,data+n);
    Solution test;
    cout<<test.hIndex(nums)<<endl;
}
