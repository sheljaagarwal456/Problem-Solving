class TrieNode {
public:
    int data;
    TrieNode* child[2];
    TrieNode(int val=0) {
        for (auto & i: child) {
            i=nullptr;
        }
        data=val;
    }
};

class Solution {
public:
    TrieNode*root;
    string intToBinary(int n) {
        int curr=n;
        string result="";    // result string
        while (curr!=0) {
            char ch=(curr % 2)+'0';  //conversion
            result+=ch;
            curr=curr/2;
        }
        return result;
    }

    void in_binary(string binary, int n, int len){
        int sz=binary.size();
        TrieNode*t=root;
        int offset=len-sz;
        for(int i=0;i<len;i++) {
            char ch='0';
            if (i>offset-1){
                ch=binary[i-offset];
            }
            int indx=ch-'0';
            if (!t->child[indx]){
                t->child[indx]=new TrieNode();
            }
            t=t->child[indx];
        }
        t->data=n;
    }

    int searchForXorPart(string binary, int len) {
        TrieNode*t=root;

        int sz=binary.size();
        int offset=len-sz;
        for(int i=0;i<len;i++) {
            int indx=0;
            if (indx> offset-1) {
                char ch=binary[i-offset];
                indx=ch-'0';
            }
            if (t->child[!indx]){ 
                t=t->child[!indx];
            }
            else {
                t=t->child[indx];
            }
        }
        return t->data;
    }

    int findMaximumXOR(vector<int>& nums) {
        root=new TrieNode();
        int n=nums.size();

        int maxLen=0;
        vector<string>binary(n);
        for (int i=0; i<n;i++) {
            int num=nums[i];
            string bin=intToBinary(num);
            if (bin.size()>maxLen){
                maxLen=bin.size();
            }
            binary[i]=bin;
        }

        for (int i=0;i<binary.size();i++) 
            in_binary(binary[i],nums[i],maxLen);

        int result=0;
        for (int i=0;i<binary.size();i++) {
            int val= searchForXorPart(binary[i],maxLen);
            int x=nums[i]^val;
            if (x>result){
                result=x;
            }
        }

        return result;
    }
};