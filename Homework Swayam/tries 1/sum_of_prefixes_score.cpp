#include<bits/stdc.h++>
using namespace std;
class Solution {
private:
    struct Trie {
        Trie *next[26]={};
        int count = 0;
    };
    Trie root;
    void insert(string s) {
        auto node = &root;
        for(auto &ch:s) {
            if(!node->next[ch-'a']) {
                node->next[ch-'a'] = new Trie();
            }
            node->next[ch-'a']->count++;
            node=node->next[ch-'a'];
        }
    }
    int prefixCount(string s) {
        auto node = &root;
        int result = 0;
        for(auto &ch:s) {
            result += node->next[ch-'a']->count;
            node=node->next[ch-'a'];
        }
        return result;
    }
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        for(auto&s:words) {
            insert(s);
        }
        vector<int> res;
        for(auto&s:words) {
            res.push_back(prefixCount(s));
        }
        return res;
    }
};