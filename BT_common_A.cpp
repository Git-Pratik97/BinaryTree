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

bool get_path(Node* root, int key, vector<int> &path)
{
    if (root == NULL)
    {
        return false;
    }

    path.push_back(root->data);

    if (root->data == key)
    {
        return true;
    }

    if (get_path(root->left, key, path) || get_path(root->right, key, path))
    {
        return true;
    }

    path.pop_back();
    return false;
}

int lowest_ca(Node* root, int n1, int n2)
{
    vector<int> path1, path2;

    if (!get_path(root, n1, path1) || !get_path(root, n2, path2))
    {
        return -1;
    }

    int pc;
    for(int pc = 0; pc < path1.size() && path2.size(); pc++)
    {
        if(path1[pc] != path2[pc])
        {
            break;
        }
    }

    return path1[pc-1];
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->left->left = new Node(7);

    int n1 = 4;
    int n2 = 5;

    int lca = lowest_ca(root, n1, n2);

    cout << lca << endl;

    return 0;
}