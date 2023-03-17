#include <iostream>

using namespace std;

struct Node{
    char key;
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

    void add(char n){
        Node * node = new Node;
        node -> key = n;
        node -> next = head;
        head = node;
    }

    char pop(){
        if (head == NULL){
            return -1;
        }
        else{
            char value = head -> key;
            head = head -> next;
            return value;
        }
    }

    char view(){
        if (head == NULL){
            return -1;
        }
        else{
            char value = head -> key;
            return value;
        }
    }

    void print(){
        if (head == NULL){
            cout << -1 << "\n";
        }
        else{
            Node * curr = head;
            while (curr){
                cout << curr -> key;
                curr = curr -> next;
            }
        }
    }
};


int main(){

    cin.tie(NULL);
    string str;
    while (cin >> str){

        Stack stack;
        bool isTrue = true;
        const char * es;
        es = str.c_str();
        int i = 0;

        while (str[i] != '\0'){

            char c = str[i];
             if (c == '('){
                 stack.add(c);
             }
             else if (c == ')'){
                 char x = stack.pop();
                 if (x != '('){
                     isTrue = false;
                     break;
                 }
             }

             if (c == '['){
                 stack.add(c);
             }
             else if (c == ']'){
                 char x = stack.pop();
                 if (x != '['){
                     isTrue = false;
                     break;
                 }
             }

             i++;

        }

//        cout << stack.view() << " " << isTrue << '\n';
        if (!isTrue || stack.view() == '(' || stack.view() == '['){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }

    }

    return 0;
}