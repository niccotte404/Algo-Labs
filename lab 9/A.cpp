#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{

    int n;
    cin >> n;
    vector <string> grayCode;

    grayCode.push_back("0");
    grayCode.push_back("1");

    for (int i = 2; i < (1 << n); i = i << 1){

        for (int j = i-1 ; j >= 0 ; j--) { // копируем
            grayCode.push_back(grayCode[j]);
        }

        for (int j = 0 ; j < i*2 ; j++) {
            if (j < i) {
                grayCode[j] = "0" + grayCode[j]; // нолики в первую часть
            }
            else{
                grayCode[j] = "1" + grayCode[j]; // единички во вторую часть
            }
        }
    }

    // вывод
    for(auto & i : grayCode) {
        cout << i << endl;
    }

    return 0;
}