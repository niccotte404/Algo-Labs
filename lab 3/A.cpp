#include <iostream>

using namespace std;

struct Node{
    int key;
    Node * next;
};

class Queue{
private:
    Node * head;
    Node * tail;

public:
    Queue(){
        head = NULL;
        tail = NULL;
    }

    void enqueue(int n){
        Node * node = new Node;
        node -> key = n;
        node -> next = NULL;

        if (head == NULL){
            head = node;
            tail = node;
        }
        else{
            tail -> next = node;
            tail = node;
        }
    }

    int dequeue(){
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
    Queue queue;
    cin.tie(NULL);

    for (int i = 0; i < n; ++i){

        char s;
        cin >> s;

        if (s == '+'){
            int k;
            cin >> k;
            queue.enqueue(k);
        }

        else{
            cout << queue.dequeue() << "\n";
        }
    }

    return 0;
}