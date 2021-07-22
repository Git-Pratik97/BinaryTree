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

int height_tree(Node* root)
{
    if (root == NULL)
    {
        return 0;
    }

    return max(height_tree(root->left), height_tree(root->right)) + 1;
}

int diameter_tree(Node* root)
{
    if (root == NULL)
    {
        return 0;
    }

    int l_height = height_tree(root->left);
    int r_height = height_tree(root->right);
    int curr_dia = l_height + r_height + 1;

    int l_dia = diameter_tree(root->left);
    int r_dia = diameter_tree(root->right);

    return max(curr_dia, max(l_dia, r_dia));
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

    cout << diameter_tree(root) << endl;

    return 0;
}