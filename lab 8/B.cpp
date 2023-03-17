#include <iostream>
#include <vector>

using namespace std;

void InsertIntoVector(vector <pair<char, int>> & msg, int n){

    char input;
    string amount;
    int amn, elem = 0, all = 0;

    for (int i = 0; i < n; i++){

        cin >> input;
        // блок, который исключает ошибку последнего символа (количество последнего из-за этого не записывалось)
        if (i == n - 1){
            amount += input;
            amn = stoi(amount);
            all += amn;
            msg[elem].second = amn;
            break;
        }
        if(!isdigit(input)){
            if (amount.length()) { // проверка, есть ли в данный момент у символа его количество
                amn = stoi(amount); // перевод str в int
                all += amn;
                msg[elem].second = amn; // запись количества вторым элементом
                elem++;
            }
            msg[elem].first = input; // запись символа первым элементом
            amount = ""; // обнуление количества
        }
        else{
            amount += input;
        }

    }
}



int main() {

    int n, m, k;
    cin >> n >> m >> k;
    vector <pair<char, int>> msg1(n);
    vector <pair<char, int>> msg2(m);

    InsertIntoVector(msg1, n);
    InsertIntoVector(msg2, m);

    int c = 0;
    int j = 0, i = 0;
    while (i < msg1.size() and j < msg2.size()) {

        if (msg1[i] != msg2[j]) {
            if (msg1[i].first != msg2[j].first) {
                c += min(msg1[i].second, msg2[j].second);
            }
        }

        if (msg1[i].second < msg2[j].second) {
            msg2[j].second -= msg1[i].second;
            i++;
        }
        else if (msg1[i].second > msg2[j].second) {
            msg1[i].second -= msg2[j].second;
            j++;
        }
        else {
            i++;
            j++;
        }

        if (c >= k) {
            cout << "No";
            return 0;
        }
    }

    cout << "Yes";
    return 0;
}
