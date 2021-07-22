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

int height_of_tree(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }

    int lh = height_of_tree(root->left);
    int rh = height_of_tree(root->right);

    return max(lh, rh) + 1;
}

bool is_balanced(Node* root)
{
    if(root == NULL)
    {
        return true;
    }

    if(is_balanced(root->left) == false)
    {
        return false;
    }

    if(is_balanced(root->right) == false)
    {
        return false;
    }

    int lh = height_of_tree(root->left);
    int rh = height_of_tree(root->right);

    if (abs(lh - rh) <= 1)
    {
        return  true;
    }
    else 
    {
        return false;
    }
}

int main()
{
    // Node* root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->right->left = new Node(6);
    // root->right->right = new Node(7);

    Node* root_2 = new Node(1);
    root_2->left = new Node(2);
    root_2->left->left = new Node(3);

    if (is_balanced(root_2))
    {
        cout << "Tree is balanced" << endl;
    }

    else
    {
        cout << "Tree is not balanced" << endl;
    }
    
    return 0;
}