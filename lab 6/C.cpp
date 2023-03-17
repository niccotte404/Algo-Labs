#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data = -1;
    Node * leftId = nullptr;
    Node * rightId = nullptr;
    int ht = -1;
};

// struct for output
struct Output{
    int key;
    int left;
    int right;

    Output() = default;

    // set values
    Output(int data, int left, int right) : key{data}, left{left}, right{right} {}
};

class AVLTree {

private:

    vector <Output> tree;

    Node * AddNodePrivate(Node * curr, int x){
        if (curr == nullptr ) {
            curr = new Node;
            curr->data = x;
            curr->ht = 0;
            curr->leftId = nullptr;
            curr->rightId = nullptr;
            return curr;
        }
        if (x < curr->data) {
            curr->leftId = AddNodePrivate(curr->leftId, x);
        }
        else {
            curr->rightId = AddNodePrivate(curr->rightId, x);
        }
        return Rebalance(curr);
    }

public:

    Node * root = nullptr;

    int Height(Node * nd) {
        if (nd == nullptr) {
            return -1;
        }
        if (nd->ht == -1){
            FixHeight(nd);
        }
        return nd->ht;
    }

    void FixHeight(Node * nd){
        nd->ht = max(Height(nd->leftId), Height(nd->rightId)) + 1;
    }

    int NodeBalance(Node * nd) {
        int htl = Height(nd->leftId);
        int htr = Height(nd->rightId);
        int bl = htr - htl;
        return bl;
    }

    Node * RightTurn(Node * a) {
        Node * b = a->leftId;
        a->leftId = b->rightId;
        b->rightId = a;
        FixHeight(a);
        FixHeight(b);
        return b;
    }

    Node * LeftTurn(Node * a) {
        Node * b = a->rightId;
        a->rightId = b->leftId;
        b->leftId = a;
        FixHeight(a);
        FixHeight(b);
        return b;
    }

    Node * Rebalance(Node * nd){
        FixHeight(nd);
        if (NodeBalance(nd) == 2) {
            if (NodeBalance(nd->rightId) < 0) {
                nd->rightId = RightTurn(nd->rightId);
            }
            return LeftTurn(nd);
        }
        if (NodeBalance(nd) == -2) {
            if (NodeBalance(nd->leftId) > 0)
                nd->leftId = LeftTurn(nd->leftId);
            return RightTurn(nd);
        }
        FixHeight(nd);
        return nd;
    }

    void AddNode(int x){
        root = AddNodePrivate(root, x);
    }

    // setting values into vector of nodes
    void ForPrint(int & curr, Node * nd){

        if (nd == nullptr){
            return;
        }
        int currTmp = curr;
        tree[curr-1].key = nd->data;
        if (nd->leftId == nullptr){
            tree[curr-1].left = 0;
        }
        else {
            tree[curr - 1].left = curr + 1;
            curr++;
            ForPrint(curr, nd->leftId);
        }

        if (nd->rightId == nullptr){
            tree[currTmp - 1].right = 0;
        }
        else {
            tree[currTmp - 1].right = curr + 1;
            curr++;
            ForPrint(curr, nd->rightId);
        }
    }

    // printing values
    void print(int n) {
        tree.resize(n);
        int i = 1;
        ForPrint(i, root);

        for (auto x: tree) {
            cout << x.key << ' ' << x.left << ' ' << x.right << '\n';
        }
    }
};



int main() {

    int n;
    cin >> n;
    int val, l, r;
    vector <Node> arr(n + 1);

    for (auto i = 0; i < n; i++) {
        cin >> val >> l >> r;
        arr[i].data = val;

        if (r - 1 != -1){
            arr[i].rightId = &arr[r - 1];
        }
        else{
            arr[i].rightId = nullptr;
        }

        if (l - 1 != -1){
            arr[i].leftId = &arr[l - 1];
        }
        else{
            arr[i].leftId = nullptr;
        }
    }

    int x;
    cin >> x;
    AVLTree avltree;
    if (n != 0){
        avltree.root = &arr[0];
    }
    avltree.AddNode(x);

    cout << n + 1 << '\n';
    avltree.print(n + 1);

    return 0;
}