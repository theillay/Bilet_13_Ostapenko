#include <iostream>
#include <limits>
#include <numeric>
#include <random>
#include <algorithm>


using namespace std;

int findMin(const int arr[], int size) {
   
    int minElement = numeric_limits<int>::max();
    for (int i = 0; i < size; ++i)
        if (arr[i] < minElement) minElement = arr[i];
    return minElement;
}

int sumBetweenPositives(const int arr[], int size) {
    int firstPositive = -1, lastPositive = -1;
    for (int i = 0; i < size; ++i)
        if (arr[i] > 0) { firstPositive = i; break; }
    for (int i = size - 1; i >= 0; --i)
        if (arr[i] > 0) { lastPositive = i; break; }
    return (firstPositive != -1 && lastPositive != -1 && firstPositive < lastPositive)
        ? accumulate(arr + firstPositive + 1, arr + lastPositive, 0)
        : 0;
}

void transformArray(int arr[], int size) {
    
    stable_partition(arr, arr + size, [](int x) { return x == 0; });
}

int main() {
 
    const int size = 10;
    int arr[size];

   
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(-10, 10);

    cout << "Created array: ";
    for (int i = 0; i < size; ++i) {
        arr[i] = dis(gen);
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Minimum array element:" << findMin(arr, size) << endl;
    cout << "The sum of elements between the first and last positive elements: "
        << sumBetweenPositives(arr, size) << endl;

    transformArray(arr, size);
    cout << "Converted array:";
    for (int i = 0; i < size; ++i) cout << arr[i] << " ";
    cout << endl;

    return 0;
}