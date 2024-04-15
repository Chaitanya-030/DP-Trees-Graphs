#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* getnode(int data) {
    Node* newnode = new Node();
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

Node* insert(Node* root, int data) {
    if(root == NULL) {
        root = getnode(data);
        return root;
    }
    else if(data <= root->data) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }
    return root;
}

bool search(Node* root, int data) {
    if(root == NULL) return false;
    else if(data < root->data) {
        return search(root->left, data);
    }
    else if(data == root->data) return true;
    else {
        return search(root->right, data);
    }
}

int main()
{
    Node* root;
    root = NULL;
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 13);
    root = insert(root, 6);
    
    int n; cin>>n;
    if(search(root, n)) cout<<"Number found!"<<endl;
    else cout<<"Number not found!"<<endl;

    return 0;
}