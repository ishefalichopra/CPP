#include <iostream>

using namespace std;

void rotateArray(int arr[], int n, int k) {
    for (int i = 0; i < k; i++) {
        int temp = arr[0];
        for (int j = 0; j < n - 1; j++)
            arr[j] = arr[j + 1];

        arr[n - 1] = temp;
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main() {
    int n; // Size of array
    cin >> n;
    int arr[n];
    //initializing array elements
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k; // No. of times to rotate
    cin >> k;
    rotateArray(arr, n, k);

    return 0;
}