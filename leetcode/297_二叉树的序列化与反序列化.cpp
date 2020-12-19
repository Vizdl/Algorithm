#include <iostream>
#include <sstream>
#include <string>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#ifndef __CODEC__
#define __CODEC__
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private :
    #define SPACE ' '
    #define NULL_NODE_STR "#"
    #define NULL_NODE_CHAR '#'
    TreeNode* deserialize_helper (const string& data, int curr, int& next) const;
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) const ;

    // Decodes your encoded data to tree.
    TreeNode* deserialize(const string& data) const;
    void print (TreeNode * root) const {
        if (root == NULL) { cout << "# "; return ; }
        cout << root->val << " ";
        print(root->left);
        print(root->right);
    }
};

/*
传入值是指针,返回值不能是引用。
*/
string Codec::serialize(TreeNode* root) const {
    if (root == NULL) return NULL_NODE_STR;
    return to_string(root->val) + SPACE + serialize(root->left) + SPACE + serialize(root->right);
}

TreeNode* Codec::deserialize_helper (const string& data, int curr, int& next) const {
    if (data[curr] == NULL_NODE_CHAR){ next = curr + 1; return NULL; }
    int end = curr + 1;
    while (end < data.size() && data[end] != SPACE) end++;
    string val = data.substr(curr, end - curr);
    TreeNode* res = new TreeNode(atoi(val.c_str()));
    TreeNode* left = deserialize_helper(data, end + 1, end);
    TreeNode* right = deserialize_helper(data, end + 1, end);
    res->left = left; res->right = right; next = end;
    return res;
}

TreeNode* Codec::deserialize(const string& data) const{
    int next;
    TreeNode* res = deserialize_helper(data, 0, next);
    if (next != data.size()) return NULL;
    return res;
}

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
#endif


int main (){
    string str = "1 2 # # 3 # 5 # #";
    const Codec c1;
    TreeNode* t = c1.deserialize(str);
    c1.print(t);
    return 0;
}