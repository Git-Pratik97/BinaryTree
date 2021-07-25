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

int max_path_sum(Node* root, int &ans)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = max_path_sum(root->left, ans);
    int right = max_path_sum(root->right, ans);

    int max_node = max(max(root->data, root->data+left+right), max(root->data + left, root->data + right));

    ans = max(ans, max_node);
    int single_path = max(root->data, max(root->data + left, root->data + right));

    return single_path;
}

int max_sum(Node* root)
{
    int ans = INT_MIN;
    max_path_sum(root, ans);

    return ans;

}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);

    cout << max_sum(root) << endl;

    return 0;
}