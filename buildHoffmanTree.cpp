#include <bits/stdc++.h>
using namespace std;

struct huffNode
{
    char ch;
    unsigned freq;

    struct huffNode *left, *right;
};

huffNode *getNewNode(char ch, int freq, huffNode *left, huffNode *right)
{
    huffNode *newNode = new huffNode();
    newNode->ch = ch;
    newNode->freq = freq;
    newNode->left = left;
    newNode->right = right;

    return newNode;
}

struct comparator
{
    bool operator()(huffNode *l, huffNode *r)
    {
        return l->freq > r->freq;
    }
};

huffNode *buildHuffmanCodes(char arr[], int freq[], int n)
{
    priority_queue<huffNode *, vector<huffNode *>, comparator> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(getNewNode(arr[i], freq[i], nullptr, nullptr));
    }

    while (pq.size() != 1)
    {
        huffNode *f = pq.top();
        pq.pop();

        huffNode *s = pq.top();
        pq.pop();

        pq.push(getNewNode('\0', f->freq + s->freq, f, s));
    }

    huffNode *root = pq.top();

    return root;
}

void showHuffCodes(huffNode *root, string s, unordered_map<char, string> &huffCodes)
{
    if (root == nullptr)
        return;
    if (root->left == NULL && root->right == NULL)
    {
        huffCodes[root->ch] = s;
    }

    showHuffCodes(root->left, s + "0", huffCodes);
    showHuffCodes(root->right, s + "1", huffCodes);
}

int main()
{
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};

    int size = sizeof(arr) / sizeof(arr[0]);

    huffNode *root = buildHuffmanCodes(arr, freq, size);
    unordered_map<char, string> huffCodes;
    string s = "";
    showHuffCodes(root, s, huffCodes);

    for (auto &it : huffCodes)
    {
        cout << it.first << "->" << it.second << endl;
    }
    return 0;
}