class Solution {
public:

    //ek function bana lo jo humein path deta rahega
    bool path(TreeNode*root,int target, string&p){
        //khali hai
        if(root==NULL){
            return false;
        }
        //mil gya
        if(root->val==target){
            return true;
        }
        //go to left
        bool left=path(root->left,target,p);
        if(left){
            p+='L';
            return true;
        }
        //go to right
        bool right=path(root->right,target,p);
        if(right){
            p+='R';
            return true;
        }
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        //root se first value tak ka path
        string start="";
        path(root,startValue, start);
        //root se dest value ka oath
        string dest="";
        path(root,destValue, dest);
        //common hata do aur i aur j ko end se leke end se first tak loop chalana 
        int i=start.size()-1;
        int j=dest.size()-1;
        while(i>=0 && j>=0 && start[i]==dest[j]){
            start.pop_back();
            dest.pop_back();
            i--;
            j--;
        }
        // u operation
        // jitns hai start utne me u daal do
        i=start.size();
        for(int j=0;j<i;j++){
            start[j]='U';
        }
        //reverse krdo kyunki abhi humpe ulti value hai
        reverse(dest.begin(),dest.end());
        return start+dest;
    }
};