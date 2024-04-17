#include <bits/stdc++.h>
using namespace std;
class TrieNode{
    public:
    char ch;
    TrieNode* children[26];
    bool isTerminal;
   string word;
   TrieNode(char ch){
    ch=ch;
    for(int i=0;i<26;i++)
    children[i]=NULL;
    isTerminal=false;
    word="";
   }
};
class Trie{
    public:
    TrieNode *root;
    Trie(){
        root=new TrieNode('\0');
    }
    void InsertUtil(TrieNode *root,string &word){

         auto child=root;

        for(int i=0;i<word.length();i++){
            int idx=word[i]-'a';
            if(child->children[idx]==NULL){
                child->children[idx]=new TrieNode(word[i]);
            }
            child=child->children[idx];
        }
        child->isTerminal=true;
        child->word=word;
    }
    string searchUtil(TrieNode* root,string &word){
          
          auto child=root;
          for(int i=0;i<word.length();i++){
            if(child->isTerminal==true)
            return child->word;

            int idx=word[i]-'a';
            if(child->children[idx]==NULL)
            return word;

            child=child->children[idx];
          }
       return word;
    }
    void Insert(string &word){
        InsertUtil(root,word);
    }
    string Search(string &word){
        return searchUtil(root,word);
    }
};
class Solution {
public:

    string replaceWords(vector<string>& dictionary, string sentence) {
        
      
           Trie* root=new Trie();

           for(auto x:dictionary)
           root->Insert(x);

           string str="";
           string ans="";

           for(int i=0;i<sentence.size();i++){
               if(sentence[i]==' '){
                   ans +=root->Search(str);
                   ans +=" ";
                   str="";
               }
               else
               str.push_back(sentence[i]);
           }
           ans +=root->Search(str);

        // ans.pop_back();
        return ans;
    }
};