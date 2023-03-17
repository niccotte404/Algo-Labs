#include <iostream>
#include <vector>

using namespace std;

struct Node{
    string key;
    Node * left = nullptr;
    Node * right = nullptr;
    int person[3] = {0};
    int ht = -1;
};

struct BinaryTree{
    Node * root = nullptr;
};


int Height(Node * nd) {
    if (nd == nullptr) {
        return -1;
    }
    if (nd->ht == -1){
        nd->ht = max(Height(nd->left), Height(nd->right)) + 1;
    }
    return nd->ht;
}


int NodeBalance(Node * nd) {
    int htl = Height(nd->left);
    int htr = Height(nd->right);
    int bl = htr - htl;
    return bl;
}

Node * RightTurn(Node * a) {
    Node * b = a->left;
    a->left = b->right;
    b->right = a;
    a->ht = max(Height(a->left), Height(a->right)) + 1;
    b->ht = max(Height(b->left), Height(b->right)) + 1;
    return b;
}

Node * LeftTurn(Node * a) {
    Node * b = a->right;
    a->right = b->left;
    b->left = a;
    a->ht = max(Height(a->left), Height(a->right)) + 1;
    b->ht = max(Height(b->left), Height(b->right)) + 1;
    return b;
}

Node * Rebalance(Node * nd){
    nd->ht = max(Height(nd->left), Height(nd->right)) + 1;
    if (NodeBalance(nd) == 2) {
        if (NodeBalance(nd->right) < 0) {
            nd->right = RightTurn(nd->right);
        }
        return LeftTurn(nd);
    }
    if (NodeBalance(nd) == -2) {
        if (NodeBalance(nd->left) > 0)
            nd->left = LeftTurn(nd->left);
        return RightTurn(nd);
    }
    nd->ht = max(Height(nd->left), Height(nd->right)) + 1;
    return nd;
}



Node * AddNode(Node * curr, string x, int i){
    if (curr == nullptr) {
        curr = new Node;
        curr->key = x;
        curr->ht = 0;
        curr->left = nullptr;
        curr->right = nullptr;
        curr->person[i]++;
        return curr;
    }
    else if (x < curr->key) {
        curr->left = AddNode(curr->left, x, i);
    }
    else if (x > curr->key) {
        curr->right = AddNode(curr->right, x, i);
    }
    else if (curr->key == x){
        curr->person[i]++;
    }
    return Rebalance(curr);
}


Node * Search(Node * node, string value, int i){
    if (node == nullptr) {
        return nullptr;
    }
    else if (node->key == value) {
        return node;
    }
    else if (node->key < value) {
        return Search(node->right, value, i);
    }
    else if (node->key > value) {
        return Search(node->left, value, i);
    }
}


void Inorder(Node * node, int * arr){
    if (node == nullptr){
        return;
    }
    Inorder(node->left, arr);

    if (node->person[0] == 1 && node->person[1] == 1 && node->person[2] == 1){

    }
    else if (node->person[0] == 1 && node->person[1] == 1){
        arr[0]++;
        arr[1]++;
    }
    else if (node->person[1] == 1 && node->person[2] == 1){
        arr[1]++;
        arr[2]++;
    }
    else if (node->person[0] == 1 && node->person[2] == 1){
        arr[0]++;
        arr[2]++;
    }
    else if (node->person[0] == 1){
        arr[0] += 3;
    }
    else if (node->person[1] == 1){
        arr[1] += 3;
    }
    else if (node->person[2] == 1){
        arr[2] += 3;
    }

    Inorder(node->right, arr);
}

int main(){

    BinaryTree * bt = new BinaryTree;
    int * arr = (int*) calloc (3, sizeof(int));
    int n;
    cin >> n;
    string f;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < n; j++){
            cin >> f;
            bt->root = AddNode(bt->root, f, i);
        }
    }

    Inorder(bt->root, arr);

    cout << arr[0] << " " << arr[1] << " " << arr[2];

    return 0;

}