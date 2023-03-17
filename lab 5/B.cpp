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

void Inorder(struct Node * node, vector <int> & arr){

    if (node == NULL){
        return;
    }
    Inorder(node->left, arr);
    arr.push_back(node->key);
    Inorder(node->right, arr);

}


int main() {
    int n, value, indLeft, indRight;
    cin >> n;

    if (n == 0) {
        cout << "YES";
        return 0;
    }

    Node * bt = new Node[n];
    vector <int> arr;
    for (int i = 0; i < n; i++) {
        cin >> value >> indLeft >> indRight;
        bt[i].key = value;
        bt[i].l = indLeft;
        bt[i].r = indRight;
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

    BT * bt1 = new BT;
    bt1->root = &bt[0];
    Inorder(bt1->root, arr);

    for (int i = 1; i < n; i++){
        if (arr[i-1] >= arr[i]){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";

    return 0;
}