#include <iostream>

using namespace std;

struct Node {
    int key;
    int height;
    int l;
    int r;
};

int main() {
    int n, value, indLeft, indRight;
    cin >> n;

    if (n == 0) {
        cout << 0;
        return 0;
    }

    Node * bt;
    bt = new Node[n];
    for (int i = 0; i < n; i++) {
        cin >> value >> indLeft >> indRight;
        bt[i].key = value;
        bt[i].l = indLeft;
        bt[i].r = indRight;
    }

    bt[0].height = 1;
    int ht = 1;
    for (int i = 0; i < n; i++) {

        indLeft = bt[i].l - 1;
        indRight = bt[i].r - 1;

        if (indLeft != -1) {
            bt[indLeft].height = bt[i].height + 1;
            if (bt[indLeft].height > ht) {
                ht = bt[indLeft].height;
            }
        }

        if (indRight != -1) {
            bt[indRight].height = bt[i].height + 1;
            if (bt[indRight].height > ht) {
                ht = bt[indRight].height;
            }
        }

    }
    cout << ht;
    return 0;
}