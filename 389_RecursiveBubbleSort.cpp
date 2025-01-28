#incluse < bits / stdc++.h>
using namespace std;

void bs(vector<int> &arr, int n)
{
    if (n == 1)
        return;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }
    bs(arr, n - 1);
}
void bubbleSort(vector<int> &arr)
{
    // Your code here
    int n = arr.size();
    bs(arr, n);
}

int main()
{
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    bubbleSort(arr);
    for (auto x : arr)
    {
        cout << x << " ";
    }
}