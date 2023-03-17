#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

struct Node{
    string key;
    Node * left;
    Node * right;
    int person[3] = {0};
};

struct BinaryTree{
    Node * root = NULL;
};

Node * Insert(Node * node, string value, int i){
    if (node == NULL){
        node = new Node;
        node->key = value;
        node->left = NULL;
        node->right = NULL;
        node->person[i]++;
    }
    else if (node->key < value){
        node->right = Insert(node->right, value, i);
    }
    else if (node->key > value){
        node->left = Insert(node->left, value, i);
    }
    else if (node->key == value){
        node->person[i]++;
    }
    return node;
}

Node * Search(Node * node, string value, int i){
    if (node == NULL) {
        return NULL;
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
    if (node == NULL){
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
            bt->root = Insert(bt->root, f, i);
        }
    }

    Inorder(bt->root, arr);

    cout << arr[0] << " " << arr[1] << " " << arr[2];

    return 0;

}