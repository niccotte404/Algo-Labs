#include <iostream>

using namespace std;

int main()
{
    // console input
    int arrayLength;
    cin >> arrayLength;
    int* array;
    array = new int [arrayLength+1];

    int nums[2];
    for (int i = 0; i < arrayLength; i++){
        cin >> array[i];
    }

    for (int i = 0; i < 2; i++){
        cin >> nums[i];
    }

    // alg body
    for (int i = arrayLength; i > nums[1] - 1; i--){
        array[i] = array[i-1];
    }
    array[nums[1]-1] = nums[0];

    // console output
    for (int i = 0; i < arrayLength + 1; i++){
        cout << array[i] << " ";
    }
    return 0;
}