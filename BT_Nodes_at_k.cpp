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

void print_subtree(Node* root, int k)
{
    if (root == NULL || k < 0)
    {
        return;
    }

    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }

    print_subtree(root->left, k-1);
    print_subtree(root->right, k-1);
}

int node_at_k(Node* root, Node* target, int k)
{
    if (root == NULL)
    {
        return -1;
    }

    if (root == target)
    {
        print_subtree(root, k);
        return 0;
    }

    int dl = node_at_k(root->left, target, k);
    if (dl != -1)
    {
        if( dl + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            print_subtree(root->right, k - dl - 2);
        }
        return dl+1;
    }

    int dr= node_at_k(root->right, target, k);
    if (dr != -1)
    {
        if( dr + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            print_subtree(root->left, k - dr - 2);
        }
        return dr+1;
    }
    return -1;
    
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);

    node_at_k(root, root->left, 1);

    return 0;
}