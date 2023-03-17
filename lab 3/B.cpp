#include <iostream>

using namespace std;

struct Node{
    int key;
    Node * next;
};

class Stack{
private:
    Node * head;
    Node * tail;

public:
    Stack(){
        head = NULL;
        tail = NULL;
    }

    void add(int n){
        Node * node = new Node;
        node -> key = n;
        node -> next = head;
        head = node;
    }

    int pop(){
        if (head == NULL){
            return -1;
        }
        else{
            int value = head -> key;
            head = head -> next;
            return value;
        }
    }
};

int main(){
    int n;
    cin >> n;
    Stack stack;
    cin.tie(NULL);

    for (int i = 0; i < n; ++i){

        char s;
        cin >> s;

        if (s == '+'){
            int k;
            cin >> k;
            stack.add(k);
        }

        else{
            cout << stack.pop() << "\n";
        }
    }

    return 0;
}