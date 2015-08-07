/**
	Word Search
	Author:Xiaojun Huang
	Date:2015-08-07

*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> >& board, string word) {
        vector<vector<bool> > isVisited;
        for(int i = 0;i < board.size();i++)
        {
            vector<bool> tmp;
            for(int j = 0;j < board[i].size();j++)
                tmp.push_back(false);
            isVisited.push_back(tmp);
        }
        for(int i = 0;i < board.size();i++)
            for(int j = 0;j < board[i].size();j++)
            {
                if(backtrace(board, isVisited, word, i, j, 0))
                    return true;
            }
        return false;
    }
    bool backtrace(vector<vector<char> >& board, vector<vector<bool> >& isVisited, string word,int x, int y, int str_index)
    {
        if(str_index >= word.size())
            return true;
        if(x < 0 || x >= board.size() || y < 0 || y >= board[x].size())
            return false;
        if(!isVisited[x][y] && board[x][y] == word[str_index])
        {
            isVisited[x][y] = true;
            int direction[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
            for(int i = 0;i < 4;i++)
            {
                if(backtrace(board, isVisited, word, x+direction[i][0], y+direction[i][1], str_index+1))
                    return true;
            }
            isVisited[x][y] = false;
            return false;
        }
        else return false;
    }
};

int main()
{
    string str_list[] = {"ABCE", "SFCS", "ADEE"};
    int n = sizeof(str_list)/sizeof(str_list[0]);
    vector<vector<char> > board;
    for(int i = 0;i < n;i++)
    {
        vector<char> tmp;
        for(int j = 0;j < str_list[i].size();j++)
            tmp.push_back(str_list[i][j]);
        board.push_back(tmp);
    }
    Solution solution;
    cout<<solution.exist(board,"SEE")<<endl;
    cout<<solution.exist(board,"ABCCED")<<endl;
    cout<<solution.exist(board,"ABCB")<<endl;
}
