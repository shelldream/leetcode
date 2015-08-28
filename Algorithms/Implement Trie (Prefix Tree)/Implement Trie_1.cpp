/*
	Implement Trie (Prefix Tree)
	Author:Xiaojun Huang
	Date:2015-08-28
*/
#include <iostream>
#include <map>
#include <memory.h>
using namespace std;

class TrieNode {
public:
    char key;
    TrieNode* next_node_map[26];
    //map<char,TrieNode*> next_node_map;
    bool isWord;
    // Initialize your data structure here.
    TrieNode(char k = '*') {
        key = k;
        isWord = false;
        for(int i = 0;i < 26;i++)
            next_node_map[i] = NULL;
        //memset(next_node_map, 26, NULL);
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
        base = 'a';
    }
    // Inserts a word into the trie.
    void insert(string word) {
        int str_len = word.length();
        TrieNode* current_node = root;
        for(int i = 0;i < str_len;i++)
        {
            if(current_node->next_node_map[word[i]-base] == NULL)
            {
                TrieNode* next_node = new TrieNode(word[i]);
                current_node->next_node_map[word[i]-base] = next_node;
                current_node = next_node;
            }
            else
            {
                current_node = current_node->next_node_map[word[i]-base];
            }
        }
        current_node->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        int str_len = word.length();
        TrieNode* current_node = root;
        for(int i = 0;i < str_len;i++)
        {
            if(current_node->next_node_map[word[i]-base] == NULL)
                return false;
            current_node = current_node->next_node_map[word[i]-base];
        }
        if(current_node->isWord)
            return true;
        else
            return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        int str_len = prefix.length();
        TrieNode* current_node = root;
        for(int i = 0;i < str_len;i++)
        {
            if(current_node->next_node_map[prefix[i]-base] == NULL)
                return false;
            current_node = current_node->next_node_map[prefix[i]-base];
        }
        return true;
    }

private:
    TrieNode* root;
    char base ;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

int main()
{
    Trie trie;
    trie.insert("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    cout<<trie.startsWith("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa")<<endl;
    //trie.insert("something");
    //cout<<trie.search("some")<<endl;
    //cout<<trie.startsWith("some")<<endl;
}

/*
±¸×¢£º

*/
