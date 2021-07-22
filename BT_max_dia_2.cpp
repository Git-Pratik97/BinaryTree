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

int max_dia(Node* root, int* height)
{
    if (root = NULL)
    {
        *height = 0;
        return 0;
    }

    int lh = 0, rh = 0;
    int l_dia = max_dia(root->left, &lh);
    int r_dia = max_dia(root->right, &rh);

    int curr_dia = lh + rh + 1;
    *height = max(lh, rh) + 1;

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
    
    int height = 0;
    cout << max_dia(root, &height) << endl;

    return 0;
}