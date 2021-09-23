#include<iostream>
#include<map>

using namespace std;

struct node
{
    node *left = nullptr;
    node *right = nullptr;
    int value = 0;
};

node* createnode(int x)
{
    node* new_node = new node;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->value = x;
    return new_node;
}

void insert(node* &root,int value)
{
    if(root == nullptr)
    {
        root = createnode(value);
        return ;
    }
    if(root->value < value)
    {
        if(root->right == nullptr) 
        {
            root->right = createnode(value);
            return;
        }
        insert(root->right,value);
    }
    if(root->value > value)
    {
        if(root->left == nullptr)
        {
            root->left = createnode(value);
            return;
        }
        insert(root->left,value);
    }
}

void preorder(node* &root)
{
    if(root->left != nullptr) preorder(root->left);
    if(root->right != nullptr) preorder(root->right);
    cout << root->value << "\n";
}

int main(void)
{
    node* root = nullptr;
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    int x;
    while(cin >> x)
    {
        if(x == EOF) break;
        insert(root,x);
    }  
    preorder(root);
}