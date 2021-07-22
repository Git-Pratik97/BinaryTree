#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void sum_replace(Node* root)
{
    if (root == NULL)
    {
        return;
    }

    sum_replace(root->left);
    sum_replace(root->right);

    if (root->left != NULL)
    {
        root->data += root->left->data;
    }
    if (root->right != NULL)
    {
        root->data += root->right->data;
    }
}

void preorder(Node* root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data <<" ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // cout << sum_replace(root) << endl;
    // cout << endl;
    preorder(root);
    cout << endl;
    sum_replace(root);
    preorder(root);
    cout << endl;
    
    return 0;
}