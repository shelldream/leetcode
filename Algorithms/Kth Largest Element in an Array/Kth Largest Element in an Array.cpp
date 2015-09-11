/**
	Kth Largest Element in an Array
	Author:Xiaojun Huang
	Date:2015-08-09

*/

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;



/** 建立小顶堆，最后取堆顶元素，即为第k大的元素
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> heap;
        heap.push_back(0);
        int heap_cap = 0;
        for(int i = 0;i < nums.size();i++)
        {
            if(heap_cap < k)
            {
                heap.push_back(nums[i]);
                heap_cap++;
                swim(heap, heap_cap);
            }
            else
            {
                if(nums[i] > heap[1])
                {
                    heap[1] = nums[i];
                    sink(heap, 1, k);
                }
            }
        }

        return heap[1];
    }
    void sink(vector<int>& heap, int i, int k)
    {
        while(2*i <= k )
        {
            int min_index = 2*i;
            if(min_index+1 <= k && heap[min_index+1] < heap[min_index] )
                min_index ++;
            if(heap[min_index] < heap[i])
            {
                int tmp = heap[i];
                heap[i] = heap[min_index];
                heap[min_index] = tmp;
                i = min_index;
            }
            else break;
        }
    }

    void swim(vector<int>& heap, int i)
    {
        while(i/2)
        {
            if(heap[i/2] > heap[i])
            {
                int tmp = heap[i/2];
                heap[i/2] = heap[i];
                heap[i] = tmp;
                i /= 2;
            }
            else break;
        }
    }
};

*/

/**快排Partition函数的应用*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int index = -1;
        int i = 0;
        int j = nums.size()-1;
        while(index != k-1)
        {
            int index = Patition(nums, i, j);
            if(index == k-1)
                return nums[index];
            else if(index > k-1)
            {
                j = index;
            }
            else
            {
                i = index;
            }
        }
    }
    int Patition(vector<int>& nums, int low, int high)
    {
        int privot_key = nums[low];
        while(low < high)
        {
            while(low < high && nums[high] >= privot_key)
                high--;
            nums[low] = nums[high];
            while(low < high && nums[low] <= privot_key)
                low++;
            nums[high] = nums[low];
        }
        nums[low] = privot_key;
        return low;
    }
};

int main()
{
    int test[] = {10, 2, 3, 1, 6, 8, 4, 5, 9, 7};
    int n = sizeof(test)/sizeof(test[0]);
    vector<int> nums(test,test+n);
    Solution solution;
    cout<<solution.findKthLargest(nums,7)<<endl;
}
