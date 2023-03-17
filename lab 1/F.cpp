#include <iostream>
using namespace std;

struct fridge
{
    int milk = 2;
    int meat = 2;
    int cheese = 6;
    int candies = 8;

    void products() {
        cout << "Milk: " << milk << endl;
        cout << "Meat: " << meat << endl;
        cout << "Cheese: " << cheese << endl;
        cout << "Candies: " << candies << endl;
        cout << endl;
    }
};

int main()
{

    fridge myFridge;
    fridge hisFridge;

    hisFridge.cheese = hisFridge.cheese - 3;
    myFridge.cheese = myFridge.cheese + 3;

    myFridge.candies = myFridge.candies - 5;
    hisFridge.candies = hisFridge.candies + 5;

    myFridge.products();
    hisFridge.products();

    return 0;
}