#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double BinarySearch(vector <double> & h, int n){

    double l = 0;
    double r = h[0];
    while (r - l > 0.000001){

        h[1] = (l + r) / 2;
        bool isTrue = true;
        for (int i = 2; i < n; i++){

            h[i] = 2 * (h[i-1] + 1) - h[i-2];
            h[i] = round(h[i] * 1000000) / 1000000;
            if (h[i] <= 0){
                isTrue = false;
                break;
            }

        }

        if (isTrue){
            r = h[1];
        }
        else{
            l = h[1];
        }

    }

    double B = h[n-1];
    return round(B * 100) / 100;

}

int main(){

    int n;
    cin >> n;
    vector <double> h(n);
    cin >> h[0];

    double B = BinarySearch(h, n);
    printf("%.2lf ", B);

    return 0;

}