/**
 *  Description: Insert Delete GetRandom O(1) https://leetcode.com/problems/insert-delete-getrandom-o1/
 *  Author:Xiaojun Huang
 *  Date:2016-08-05
 */
#include <iostream>
#include <unordered_map>
#include <vector>
#include <stdlib.h>
#include<time.h>
using namespace std;

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        _val_map.clear();
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        unordered_map<int, int>::iterator iter = _val_map.find(val);
        if (iter == _val_map.end())
        {
            _val_vec.push_back(val);
            _val_map[val] = _val_vec.size()-1;
            return true;
        }
        return false;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        unordered_map<int, int>::iterator iter = _val_map.find(val);
        if (iter != _val_map.end())
        {
            int last_index = _val_vec.size()-1;
            if (last_index != 0) //如果RandomizedSet中不只有一个元素
            {
                int del_index = _val_map[val]; //待删除元素的下标
                _val_vec[del_index] = _val_vec[last_index];
                _val_map[_val_vec[last_index]] = del_index;
            }
            _val_vec.pop_back();
            _val_map.erase(val);
            return true;
        }
        return false;
    }

    /** Get a random element from the set. */
    int getRandom() {
        srand((int)time(0));
        int randInt = rand();
        randInt %= _val_vec.size();
        if (randInt >= 0)
            return _val_vec[randInt];
        return -1;
    }
private:
    unordered_map<int,int> _val_map;
    vector<int> _val_vec;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

int main()
{
    RandomizedSet randomSet;
    cout<<randomSet.insert(1)<<endl;
    cout<<randomSet.remove(2)<<endl;
    cout<<randomSet.insert(2)<<endl;
    cout<<randomSet.insert(3)<<endl;
    cout<<randomSet.insert(4)<<endl;
    cout<<randomSet.insert(5)<<endl;
    cout<<randomSet.insert(6)<<endl;
    cout<<randomSet.getRandom()<<endl;
    cout<<randomSet.remove(1)<<endl;
    cout<<randomSet.insert(2)<<endl;
    cout<<randomSet.getRandom()<<endl;
}
