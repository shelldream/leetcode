/*
	Add and Search Word
	Author:Xiaojun Huang
	Date:2015-07-27

*/

#include <iostream>
#include <map>
using namespace std;

struct node
{
    char c;
    map<char,node*> next;
    bool isEnd;
    node(char a)
    {
        c = a;
        isEnd = false;
    }
};

class WordDictionary {
public:
    // Adds a word into the data structure.
    void addWord(string word) {
        node* current = root;
        for(int i = 0;i < word.length();i++)
        {
            if(current->next.count(word[i])==0)
            {
                node* tmp = new node(word[i]);
                current->next[word[i]] = tmp;
                current = tmp;
            }
            else
            {
                current = current->next[word[i]];
            }
            if(i == word.length()-1)
                current->isEnd = true;
        }
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search_trie(string word,node* sub_root)//以sub_root为根节点
    {
        if(word[0] != '.')
        {
            if(sub_root->next.count(word[0]))
            {
                if(word.length() == 1)
                {
                    if(sub_root->next[word[0]]->isEnd)
                        return true;
                    else
                        return false;
                }
                return search_trie(word.substr(1,word.length()-1),sub_root->next[word[0]]);
            }

            else return false;
        }
        else
        {
            if(word.length() == 1)
            {
                map<char,node*>::iterator iter;
                for(iter=sub_root->next.begin();iter!=sub_root->next.end();iter++)
                {
                    node* tmp = iter->second;
                    if(tmp->isEnd)
                        return true;
                }
                return false;
            }
            map<char,node*>::iterator iter;
            for(iter=sub_root->next.begin();iter!=sub_root->next.end();iter++)
            {
                node* tmp = iter->second;
                if(search_trie(word.substr(1,word.length()-1),tmp))
                    return true;
            }
            return false;
        }

    }
    bool search(string word) {
        return search_trie(word,root);

    }
    WordDictionary()
    {
        root = new node('*');
    }

private:
    node* root;

};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");




int main()
{
    WordDictionary test;
    test.addWord("bad");
    test.addWord("pad");
    test.addWord("mad");
    cout<<test.search("pad")<<endl;
    cout<<test.search("bad")<<endl;
    cout<<test.search(".ad")<<endl;
    cout<<test.search("b..")<<endl;
    cout<<test.search("...")<<endl;
    cout<<test.search(".a.")<<endl;
    cout<<test.search(".e.")<<endl;
}

/*说明


*/
