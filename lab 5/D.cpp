#include <iostream>

using namespace std;

struct Node{
    int key;
    Node * left;
    Node * right;
    Node (int value){
        key = value;
        left = NULL;
        right = NULL;
    }
};

class BinaryTree {

public:

    Node * root;

    BinaryTree(){
        root = NULL;
    }

    void PrivateInsert(Node * node, int value) {
        if (value < node->key) {
            if (node->left != NULL) {
                PrivateInsert(node->left, value);
            } else {
                node->left = new Node(value);
            }
        } else if (value >= node->key) {
            if (node->right != NULL) {
                PrivateInsert(node->right, value);
            } else {
                node->right = new Node(value);
            }
        }
    }

    void Insert(int value) {
        if (root != NULL) {
            PrivateInsert(root, value);
        } else {
            root = new Node(value);
        }
    }

    Node *MinElem(Node *node) {
        if (node->left != NULL) {
            return MinElem(node->left);
        }
        return node;
    }

    bool Search(Node * node, int value) {
        if (node == NULL) {
            return false;
        } else if (node->key == value) {
            return true;
        } else if (node->key < value) {
            return Search(node->right, value);
        } else if (node->key > value) {
            return Search(node->left, value);
        }
    }

    Node *Next(Node *root, int x) {
        Node *curr = root, *successor = NULL;
        while (curr != NULL) {
            if (curr->key > x) {
                successor = curr;
                curr = curr->left;
            } else {
                curr = curr->right;
            };
        };
        return successor;
    }

    Node *Prev(Node *root, int x) {
        Node *curr = root, *successor = NULL;
        while (curr != NULL) {
            if (curr->key < x) {
                successor = curr;
                curr = curr->right;
            } else {
                curr = curr->left;
            }
        }
        return successor;
    }

    Node *PrivateRemove(Node *node, int value) {
        if (node == NULL) {
            return node;
        }
        if (node->key > value) {
            node->left = PrivateRemove(node->left, value);
        } else if (node->key < value) {
            node->right = PrivateRemove(node->right, value);
        } else if ((node->left != NULL) && (node->right != NULL)) {
            node->key = MinElem(node->right)->key;
            node->right = PrivateRemove(node->right, node->key);
        } else {
            if (node->left != NULL) {
                node = node->left;
            } else if (node->right != NULL) {
                node = node->right;
            } else {
                node = NULL;
            }
        }
        return node;
    }

    void Remove(int value) {
        if (root != NULL) {
            root = PrivateRemove(root, value);
        }
    }

};

int main(){

    BinaryTree binaryTree;
    binaryTree.root = NULL;
    int n;
    string s;
    while (cin >> s){
        if (s == "insert"){
            cin >> n;
            if (!binaryTree.Search(binaryTree.root, n)) {
                binaryTree.Insert(n);
            }
        }
        else if (s == "delete"){
            cin >> n;
            binaryTree.Remove(n);
        }
        else if (s == "exists"){
            cin >> n;
            bool exists_node = binaryTree.Search(binaryTree.root, n);
            if (exists_node){
                cout << "true" << "\n";
            }
            else {
                cout << "false" << "\n";
            }
        }
        else if (s == "next"){
            cin >> n;
            Node * nd = binaryTree.Next(binaryTree.root, n);
            if (nd != NULL) {
                cout << nd -> key << "\n";
            }
            else {
                cout << "none" << "\n";
            }
        }
        else if (s == "prev"){
            cin >> n;
            Node * nd = binaryTree.Prev(binaryTree.root, n);
            if (nd != NULL) {
                cout << nd -> key << "\n";
            }
            else {
                cout << "none" << "\n";
            }
        }
    }
    return 0;

}