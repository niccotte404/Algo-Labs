#include <iostream>
#include <vector>

using namespace std;

struct Node {
    struct Node * left = NULL;
    struct Node * right = NULL;
    int key;
    int l;
    int r;
};

struct BT{
    Node * root;
};

void Inorder(struct Node * node, int &i){

    if (node == NULL){
        return;
    }
    Inorder(node->left, i);
    if (node->key == 0) {
        node->key = i;
        i++;
    }
    Inorder(node->right, i);

}


int main() {
    int n, indLeft, indRight;
    cin >> n;

    Node * bt = new Node[n];
    vector <int> arr;
    for (int i = 0; i < n; i++) {

        cin >> indLeft >> indRight;
        bt[i].l = indLeft;
        bt[i].r = indRight;
        bt[i].key = 0;

    }

    for (int i = 0; i < n; i++) {

        indLeft = bt[i].l - 1;
        indRight = bt[i].r - 1;

        if (indLeft != -1) {
            bt[i].left = &bt[indLeft];
        }

        if (indRight != -1) {
            bt[i].right = &bt[indRight];
        }

    }

    BT *bt1 = new BT;
    bt1->root = &bt[0];

    int x = 1;
    Inorder(bt1->root, x);
    for (int i = 0; i < n; i++) {
        cout << bt[i].key << " ";
    }

    return 0;
}