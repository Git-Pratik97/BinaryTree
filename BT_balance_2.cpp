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

bool is_balanced(Node* root, int* height)
{
    if (root == NULL)
    {
        return true;
    }

    int lh = 0, rh = 0;
    if (is_balanced(root->left, &lh) == false)
    {
        return false;
    }
    if (is_balanced(root->right, &rh) == false)
    {
        return false;
    }

    *height = max(lh, rh) + 1;
    if (abs(lh - rh) <= 1)
    {
        return true;
    }
    else 
    {
        return false;
    }
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

    Node* root_2 = new Node(1);
    root_2->left = new Node(2);
    root_2->left->left = new Node(3);

    int height = 0;
    if(is_balanced(root_2, &height))
    {
        cout << "Balanced" << endl;
    }
    else
    {
        cout << "Unbalanced" << endl;
    }

    return 0;
}