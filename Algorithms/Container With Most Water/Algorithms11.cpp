/*
    Container With Most Water
	Author:Xiaojun Huang
	Date:2015-07-11
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int i = 0;
        int j = height.size()-1;
        while(i<j)
        {
            int area = min(height[i],height[j])*(j-i);
            if(area>ans)
                ans = area;
            if(height[i]<height[j])
                i++;
            else
                j--;
        }
        return ans;
    }
};



int main()
{
    Solution solution;
    int test[] = {1,3,4,10};
    int n = sizeof(test)/sizeof(test[0]);
    vector<int> vec(test,test+n);
    cout<<solution.maxArea(vec);

}

/*
±¸×¢£º

*/
