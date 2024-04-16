#include <bits/stdc++.h>
using namespace std;
class Trie {
public:
    bool end;
    vector<Trie*> v;

    Trie() {
        end = false;
        v.resize(26, nullptr);
    }
    
    void insert(string word) {
        Trie* node = this;
        for (int i=0;i<word.length(); i++){
            if (!node->v[word[i] - 'a']){
                node->v[word[i] - 'a'] = new Trie();
                
            }
            node = node->v[word[i] - 'a'];
        }
        node->end = true;
    }
    
    bool search(string word) {
        Trie* node = this;
        for (int i = 0;i<word.length(); i++){
            if(!node->v[word[i]-'a']) return false;
            node = node->v[word[i] - 'a'];
        }
        return node->end;
    }
    
    bool startsWith(string prefix) {
        Trie *node = this;
        for (int i = 0;i<prefix.length(); i++){
            if (!node->v[prefix[i] - 'a']) return false;
            node = node->v[prefix[i] - 'a'];
        }
        return true;
    }
};