using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

struct Node
{
    int left;
    int right;
};

Node tree[26];

void PreOder(int cur)
{
    if (cur == -1)
        return;

    cout << static_cast<char>(cur + 'A');
    PreOder(tree[cur].left);
    PreOder(tree[cur].right);
}
void InOder(int cur)
{
    if (cur == -1)
        return;

    InOder(tree[cur].left);
    cout << static_cast<char>(cur + 'A');
    InOder(tree[cur].right);
}
void PostOder(int cur)
{
    if (cur == -1)
        return;

    PostOder(tree[cur].left);
    PostOder(tree[cur].right);
    cout << static_cast<char>(cur + 'A');
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        char parent, left, right;
        cin >> parent >> left >> right;

        int cur = parent - 'A';
        tree[cur].left = left == '.' ? -1 : left - 'A';
        tree[cur].right = right == '.' ? -1 : right - 'A';
    }

    PreOder(0);
    cout << '\n';
    InOder(0);
    cout << '\n';
    PostOder(0);

    return 0;
}