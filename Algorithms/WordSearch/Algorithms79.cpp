/*
    Description:
        Word Search
        https://leetcode.com/problems/word-search/description/
        Author: shelldream
    Date:2017-11-13
*/
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> >& board, string word) {
        int m = board.size();
        if (0 == m)
            return false;
        
        int n = board[0].size();
        
        if (word.empty())
            return false;
        
        for (size_t i = 0; i < m; ++i)
        {
            for (size_t j = 0; j < n; ++j)
            {
                if (board[i][j] == word[0])
                {
                    vector<vector<bool> > isVisited(m, vector<bool>(n, false));
                    if (DFS(board, i, j, word, 0, isVisited, m, n))
                        return true;
                }
            }
        }

        return false;
    }

    bool DFS(vector<vector<char> > &board, int i, int j, string word, int k, vector<vector<bool> > &isVisited, int m, int n)
    {
        if (i < 0 || i >= m || j < 0 || j >= n)
            return false;

        if (board[i][j] != word[k] || isVisited[i][j])
            return false;
         
        isVisited[i][j] = true;
        
        if (k >= word.size()-1)
            return true;
        
        if (DFS(board, i-1, j, word, k+1, isVisited, m, n))
        {
           isVisited[i-1][j] = false;
           return true;     
        }
        
        if (DFS(board, i, j+1, word, k+1, isVisited, m, n))
        {
           isVisited[i][j+1] = false;
           return true;     
        }
        
        if (DFS(board, i+1, j, word, k+1, isVisited, m, n))
        {
           isVisited[i+1][j] = false;
           return true; 
        }

        if (DFS(board, i, j-1, word, k+1, isVisited, m, n))
        {
           isVisited[i][j-1] = false;
           return true; 
        }

        isVisited[i][j] = false;

        return false;
    } 
};

int main()
{
    Solution solution;
    string board_str[3] = {"ABCE", "SFES", "ADEE"};
    vector<vector<char> > board;
    board.push_back(vector<char>(board_str[0].begin(), board_str[0].end())); 
    board.push_back(vector<char>(board_str[1].begin(), board_str[1].end())); 
    board.push_back(vector<char>(board_str[2].begin(), board_str[2].end()));
    
    cout << solution.exist(board, string("ABCEFSADEESE")) << endl; 
}

