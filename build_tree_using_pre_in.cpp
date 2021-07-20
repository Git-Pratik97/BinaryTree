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

int search(int inorder[], int start, int end, int curr)
{
    for(int i = start; i <= end; i++)
    {
        if(inorder[i] == curr)
        {
            return i;
        }
    }
    return -1;
}

Node* build_tree(int preorder[], int inorder[], int start, int end)
{
    static int idx = 0;
    if (start > end)
    {
        return NULL;
    }

    int curr = preorder[idx];
    idx++;
    Node* node = new Node(curr);

    if (start == end)
    {
        return node;
    }

    int pos = search(inorder, start, end, curr);
    node->left = build_tree(preorder, inorder, start, pos-1);
    node->right = build_tree(preorder, inorder, pos+1, end);

    return node;
}

void print_inorder(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    print_inorder(root->left);
    cout << root->data << " ";
    print_inorder(root->right);
}

int main()
{
    int preorder[] = {1, 2, 4, 3, 5};
    int inorder[] = {4, 2, 1, 5, 3};

    Node* root = build_tree(preorder, inorder, 0, 4);
    
    print_inorder(root);

    return 0;
}