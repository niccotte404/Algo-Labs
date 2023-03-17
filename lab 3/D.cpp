#include <iostream>
#include <vector>
#include <sstream>
#include <string>

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

    void print(){
        if (head == NULL){
            cout << -1 << "\n";
        }
        else{
            Node * curr = head;
            while (curr){
                cout << curr -> key << " ";
                curr = curr -> next;
            }
        }
    }
};

void Tokinize(string const &str, vector <string> &out){
    stringstream ss(str);
    string s;
    while (getline(ss, s, ' ')){
        out.push_back(s);
    }
}

int main(){

    char str[256];
    scanf("%255[^\n]s", str);
    vector <string> out;
    Stack stack;
    Tokinize(str, out);

    cin.tie(NULL);

    for (auto &str: out){
        if (str == "+"){
            auto a = stack.pop();
            auto b = stack.pop();
            stack.add(a + b);
        }
        else if (str == "-"){
            auto a = stack.pop();
            auto b = stack.pop();
            stack.add(b - a);
        }
        else if (str == "*"){
            auto a = stack.pop();
            auto b = stack.pop();
            stack.add(a * b);
        }
        else{
            int n = stoi(str);
            stack.add(n);
        }
    }

    stack.print();

    return 0;
}