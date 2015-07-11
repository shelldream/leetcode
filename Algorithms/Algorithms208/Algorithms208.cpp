/*
	Implement Trie (Prefix Tree)
	Author:Xiaojun Huang
	Date:2015-07-08
*/
#include <iostream>
#include <map>
using namespace std;

class TrieNode {
public:
    char key;
    map<char,TrieNode*> next_node_map;
    // Initialize your data structure here.
    TrieNode(char k = '*') {
        key = k;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    // Inserts a word into the trie.
    void insert(string word) {
        int str_len = word.length();
        TrieNode* current_node = root;
        for(int i = 0;i < str_len;i++)
        {
            TrieNode* next_node = new TrieNode(word[i]);
            current_node->next_node_map[word[i]] = next_node;
            current_node = next_node;
        }
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        int str_len = word.length();
        TrieNode* current_node = root;
        for(int i = 0;i < str_len;i++)
        {
            if(current_node->next_node_map.count(word[i])==0)
                return false;
            current_node = current_node->next_node_map[word[i]];
        }
        if(current_node->next_node_map.size() == 0)
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
            if(current_node->next_node_map.count(prefix[i])==0)
                return false;
            current_node = current_node->next_node_map[prefix[i]];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

int main()
{
    Trie trie;
    trie.insert("something");
    cout<<trie.search("some")<<endl;
    cout<<trie.startsWith("some")<<endl;
}

/*
±¸×¢£º

*/
