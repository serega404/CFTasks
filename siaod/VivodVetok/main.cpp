#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Node {
    int data;
    struct Node *left = nullptr;
    struct Node *right = nullptr;
} *Tree;

vector<int> chisla;

void tree_insert(Tree &t, int data) {
    if (t == nullptr) {
        t = new Node;
        t->data = data;
    } else {
        if (data < t->data) {
            tree_insert(t->left, data);
        } else {
            tree_insert(t->right, data);
        }
    }
}

int find(Tree T, int data) {
    if (T == nullptr) {
        return 0;
    } else {
        if (T->data == data) {
            return 1;
        } else if (data < T->data) {
            return find(T->left, data);
        } else {
            return find(T->right, data);
        }
    }
}

void findOneChild(Tree T) {
    if (T->left != nullptr && T->right != nullptr) {
        findOneChild(T->left);
        findOneChild(T->right);
    } else if (T->left != nullptr && T->right == nullptr) {
        chisla.push_back(T->data);
        findOneChild(T->left);
    } else if (T->left == nullptr && T->right != nullptr) {
        chisla.push_back(T->data);
        findOneChild(T->right);
    }
}

int main() {
    Tree T = nullptr;

    int n;
    cin >> n;
    for (; n != 0; cin >> n) {
        if (!find(T, n))
            tree_insert(T, n);
    }

    findOneChild(T);

    sort(chisla.begin(), chisla.end());

    for (int k : chisla) {
        cout << k << endl;
    }

    return 0;
}


