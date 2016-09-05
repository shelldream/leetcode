/**
 *  Description: Shuffle an Array https://leetcode.com/problems/shuffle-an-array/
 *  Author:Xiaojun Huang
 *  Date: 2016-08-26
 */
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;


class Solution {
public:
    Solution(vector<int> nums) {
        _nums.assign(nums.begin(), nums.end());
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return _nums;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res(_nums.begin(), _nums.end());
        for (size_t i = 0; i < _nums.size(); ++i)
        {
            srand((int)time(0));
            long long tmp = 0;
            while (tmp < 50000000)
                ++tmp;
            int randInt = rand()%(_nums.size()-1);
            swap(res[i], res[randInt]);
        }
        return res;
    }

private:
    vector<int> _nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */

void print_vec(vector<int> &nums)
{
    for (size_t i = 0; i < nums.size(); ++i)
        cout<<nums[i]<<"  ";
    cout<<endl;
}

int main()
{
    int data[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int N = sizeof(data)/sizeof(data[0]);
    vector<int> nums(data,data+N);
    Solution solution(nums);
    vector<int> new_nums1 = solution.shuffle();
    print_vec(new_nums1);
    vector<int> new_nums2 = solution.shuffle();
    print_vec(new_nums2);
    vector<int> new_nums3 = solution.reset();
    print_vec(new_nums3);
    vector<int> new_nums4 = solution.shuffle();
    print_vec(new_nums4);
}

