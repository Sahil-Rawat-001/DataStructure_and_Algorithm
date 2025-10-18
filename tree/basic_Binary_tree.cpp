#include<iostream>

using namespace std;


class Node{
    public:
    int data;
    Node* left;
    Node* right;

    // constructor
    Node(int d){
        data = d;
        left = nullptr;
        right =nullptr;
    }
};

void preOrderTraversalRec(Node* newNode){
    if(newNode == nullptr){
        return;
    }
    cout << newNode-> data << " ";
    preOrderTraversalRec(newNode->left);
    preOrderTraversalRec(newNode->right);
}

void inOrderTraversalRec(Node* newNode){
    if(newNode == nullptr){
        return;
    }
    inOrderTraversalRec(newNode->left);
    cout << newNode-> data << " ";
    inOrderTraversalRec(newNode->right);
}

void postOrderTraversalRec(Node* newNode){
    if(newNode == nullptr) return;
    postOrderTraversalRec(newNode->left);
    postOrderTraversalRec(newNode->right);
    cout << newNode-> data << " ";
}

int main(){
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right =  new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);

    // cout << "Root: " << root -> data << endl;
    // cout << "Root  left child: " << root ->left->data << endl;
    // cout << "Root  right child: " << root ->right->data << endl; 
    // cout << "Root  left left child: " << root ->left->left->data << endl;
    // cout << "Root  left right child: " << root ->left->right->data << endl;
    
    // preOrderTraversal(root);
    // inOrderTraversal(root);
    postOrderTraversalRec(root);

    
    return 0;
}