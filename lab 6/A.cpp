#include <iostream>

using namespace std;

struct Node {
    int l;
    int r;
    int height = 0;
};

int Height(Node * bt, int i) {
    if (bt[i].l != -1 && bt[i].r != -1) {
        return max(bt[bt[i].l].height, bt[bt[i].r].height) + 1;
    }
    else if (bt[i].l == -1 && bt[i].r != -1) {
        return bt[bt[i].r].height + 1;
    }
    else if (bt[i].l != -1 && bt[i].r == -1) {
        return bt[bt[i].l].height + 1;
    }
    else {
        return 1;
    }
}

void Count(Node * bt, int i = 0) {
    if (bt[i].l != -1) {
        Count(bt, bt[i].l);
    }
    if (bt[i].r != -1) {
        Count(bt, bt[i].r);
    }
    bt[i].height = Height(bt, i);
}

int main() {
    int n, value, indLeft, indRight;
    scanf("%d", &n);

    if (n == 0) {
        printf("0");
        return 0;
    }

    Node * bt;
    bt = new Node[n];
    int bl;
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &value, &indLeft, &indRight);
        bt[i].l = indLeft - 1;
        bt[i].r = indRight - 1;

    }

    Count(bt);
    for (int i = 0; i < n; ++i){
        if (bt[i].l == -1 && bt[i].r == -1){
            bl = 0;
        }
        else if (bt[i].l != -1 && bt[i].r != -1){
            bl = bt[bt[i].r].height - bt[bt[i].l].height;
        }
        else if (bt[i].l != -1 && bt[i].r == -1){
            bl = -bt[bt[i].l].height;
        }
        else if (bt[i].l == -1 && bt[i].r != -1){
            bl = bt[bt[i].r].height;
        }

        printf("%d\n", bl);
    }

    return 0;
}