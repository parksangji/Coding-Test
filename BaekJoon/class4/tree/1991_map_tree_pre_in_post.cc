#include<iostream>
#include<map>

using namespace std;
map<char,pair<char,char>> m;
void preorder(char cur)
{
    if(cur == '.') return;
    cout << cur;
    preorder(m[cur].first);
    preorder(m[cur].second);
}
void inorder(char cur)
{
    if(cur == '.') return;
    inorder(m[cur].first);
    cout << cur;
    inorder(m[cur].second);
}

void postorder(char cur)
{
    if(cur == '.') return;
    postorder(m[cur].first);
    postorder(m[cur].second);
    cout << cur;
}

int main(void)
{
    int n;
    cin >> n;

    for(int i=0; i< n; i++)
    {
        char parent, leftChild, rightChild;
        cin >> parent >> leftChild >> rightChild;
        m[parent] = {leftChild,rightChild};
    }
    preorder('A');
    cout << "\n";
    inorder('A');
    cout << "\n";
    postorder('A');
}