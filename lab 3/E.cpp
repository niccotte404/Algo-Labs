#include <iostream>
#include <string>

using namespace std;

struct Node{
    int key;
    int mx;
    Node * next;
};

class Stack{
private:

    Node * head;
    Node * copy;

public:

    Stack(){
        head = NULL;
    }

    void add(int n){

        Node * node = new Node;
        node -> key = n;

        if (head){
            if (head -> mx < n){
                node -> mx = n;
            }
            else{
                node -> mx = head -> mx;
            }
            node -> next = head;
            head = node;
        }
        else{
            node -> mx = n;
            node -> next = head;
            head = node;
        }

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

    int max(){

        int value = head -> mx;
        return value;

    }

};


int main() {

    Stack stack;
    int n;
    cin >> n;
    cin.tie(NULL);

    for (int i = 0; i < n; i++){

        string sign;
        cin >> sign;

        if (sign == "+"){
            int num;
            cin >> num;
            stack.add(num);
        }

        else if (sign == "-"){
            int x = stack.pop();
        }

        else if (sign == "max"){
            int x = stack.max();
            cout << x << '\n';
        }
    }
    return 0;

}
