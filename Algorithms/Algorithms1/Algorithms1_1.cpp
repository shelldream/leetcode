/*
	Two Sum 
	Author:Xiaojun Huang
	Date:2015-3-11
	
*/

#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int,int> index_num;
        int size = numbers.size();
        for(int i = 0;i < size;i++){
            map<int,int>::iterator iter = index_num.find(target - numbers[i]);
            if(iter != index_num.end()){
                vector<int> ans;
                ans.push_back(iter->second);
                ans.push_back(i+1);
                return ans;
            }
            else
                index_num[numbers[i]] = i+1;
        }
    }
};

int main()
{
	int data[] = {2,7,11,15};
	int size = sizeof(data)/sizeof(data[0]);
	vector<int> numbers(data,data+size);
	int target = 9;
	Solution solution;
	vector<int> ans = solution.twoSum(numbers,target);
	cout<<ans[0]<<"  "<<ans[1]<<endl;
}

/*说明

使用map，查找时间复杂度O(logn)

*/ 