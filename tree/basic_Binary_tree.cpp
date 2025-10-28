#include<iostream>
#include<vector>
#include<queue>

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

// Depth First search techniques

void preOrderTraversalRec(TreeNode* node){
    if(node == nullptr){
        return; 
    }
    cout << node-> data << " ";
    preOrderTraversalRec(node->left);
    preOrderTraversalRec(node->right);
}

void inOrderTraversalRec(TreeNode* node){
    if(node == nullptr){
        return;
    }
    inOrderTraversalRec(node->left);
    cout << node-> data << " ";
    inOrderTraversalRec(node->right);
}

void postOrderTraversalRec(TreeNode* node){
    if(node == nullptr) return;
    postOrderTraversalRec(node->left);
    postOrderTraversalRec(node->right);
    cout << node-> data << " ";
}

// Breadth first search technique

vector<vector<int>> levelOrderTraversal(TreeNode* root){
    vector<vector<int>> ans;
    if(root == nullptr) return ans;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        vector<int> level;

        for(int i = 0; i < size; i++){
            TreeNode* newNode = q.front();
            q.pop();
            if(newNode -> left != NULL) q.push(newNode->left);
            if(newNode -> right != NULL) q.push(newNode->right);
            level.push_back(newNode->data);
        }
        ans.push_back(level);
    }
    return ans;
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

    // cout << "Root: " << root -> data << endl;
    // cout << "Root  left child: " << root ->left->data << endl;
    // cout << "Root  right child: " << root ->right->data << endl; 
    // cout << "Root  left left child: " << root ->left->left->data << endl;
    // cout << "Root  left right child: " << root ->left->right->data << endl;
    
    // preOrderTraversal(root);
    // inOrderTraversal(root);
    // postOrderTraversalRec(root);
    vector<vector<int>> result = levelOrderTraversal(root);
    displayLevelOrderTraversal(result);

    return 0;
}