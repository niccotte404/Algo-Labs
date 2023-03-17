#include <iostream>
#include <string>
#include <cmath>

using namespace std;


int Decode(string &msg){
    int wrongIndex = 0;
    for (int i = 1; i < msg.length() + 1; i++){
        if (msg[i-1] == '1'){
            wrongIndex ^= i;
        }
    }
    return wrongIndex;
}


int main(){

    int n;
    cin >> n;
    string msg;
    int wrongIndex;
    for (int i = 0; i < n; i++){
        cin >> msg;
        wrongIndex = Decode(msg);
        if (wrongIndex != 0) {
            if (msg[wrongIndex - 1] == '1') {
                msg[wrongIndex - 1] = '0';
            } else {
                msg[wrongIndex - 1] = '1';
            }
        }
        for (int j = 1; j < msg.length()+1; j++){
            if (pow(2, (int)log2(j)) != j){
                cout << msg[j-1];
            }
        }
        cout << "\n";
    }

    return 0;
}