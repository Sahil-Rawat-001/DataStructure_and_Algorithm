#include<iostream>
#include<vector>
#include<stack>

using namespace std;


class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;

    // constructor
    TreeNode(int d){
        data = d;
        left = nullptr;
        right =nullptr;
    }
};

void preInPostInOne(TreeNode* root){
    stack<pair<TreeNode*,int>> s;
    s.push({root,1});

    vector<int> pre, in, post;
    if(root == nullptr) return;

    while(!s.empty()){
        auto it = s.top();
        s.pop();

        // this is part of pre 
        // increment 1 to 2
        // push the left side of the tree
        if(it.second == 1){
            pre.push_back(it.first->data);
            it.second++;
            s.push(it);
            if(it.first->left != nullptr){
                s.push({it.first->left,1});
            }
        }
        // this is part of inorder
        // increment 2 to 3
        // push the right of the tree
        else if(it.second == 2){
            in.push_back(it.first->data);
            it.second++;
            s.push(it);
            if(it.first->right != nullptr){
                s.push({it.first->right,1});
            }
        }else{
            post.push_back(it.first->data);
        }
    }

    // pre
    for(auto it : pre){
        cout << it << " ";
    }   
    cout << endl;
    // in
    for(auto it : in){
        cout << it << " ";
    } 
    cout << endl;
    for(auto it : post){
        cout << it << " ";
    } 
}

void displayLevelOrderTraversal(vector<vector<int>> result){
    for(auto level : result){
        for (auto node : level){
            cout << node << " ";
        }
        cout << endl;
    }
}

int main(){
    TreeNode* root = new TreeNode(1);
    root -> left = new TreeNode(2);
    root -> right =  new TreeNode(3);
    root -> left -> left = new TreeNode(4);
    root -> left -> right = new TreeNode(5);
    root -> right -> left = new TreeNode(6);
    root -> right -> right = new TreeNode(7);

   preInPostInOne(root);

    return 0;
}